//
// Created by yaroslav_admin on 12.10.22.
//

#include <GL/gl.h>
#include <GL/freeglut.h>

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

#include <pthread.h>
#include <chrono>
#include <thread>

bool can_play = true;
std::string current_music;
bool run = true;

std::vector<std::vector<double>> points;
bool locked_by_draw = false;


int mode_a = 10; // 1 or 5 or 10 or 15
int mode_b = 1;

std::map<char, int> levels;


// Q  A  W  S  E  D  R  F  T  G  Y  H  U  J
// 1  2  3  4  5  6  7  8  9  10 11 12 13 14


void next_graphic_position()
{
    for (unsigned int i = 0 ; i < points.size(); i++){
        points[i][0] -= 0.5;
    }
    for (unsigned int i = 0 ; i < points.size(); i++){
            if (points[i][0] < -10.0){
                points.erase(points.begin() + i);
                break;
            }
    }
}

//void *next_graphic_position_worker(void * args)
//{
//    while(true){
//        while (locked_by_draw)
//            usleep(10);
//        next_graphic_position();
//        usleep(10);
//    }
//}

void Draw() {

    locked_by_draw = true;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPointSize(6);
    glColor4f(1.0f,1.0f,1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    //glVertex2f(0.0f, -1.0f);
    //glVertex2f(0.0f, 1.0f);

    glColor4f(0.4f,1.0f,0.7f, 1.0f);
    if (points.size() != 0)
        for (unsigned int i = 0; i < (points.size() - 1); i++){
            // std::cout << "Drawing :" << ((float)points[i][0]) / 10 << "|" << ((float)points[i][1]) / 10 << "\n";
            glVertex2f( ((float)points[i][0]) / 10, ((float)points[i][1]) / 10 );
            glVertex2f( ((float)points[i + 1][0]) / 10, ((float)points[i + 1][1]) / 10 );
        }
    glEnd();



    // glFlush();
    glutSwapBuffers();//прорисовываем буфер на экран
    locked_by_draw = false;


}


void init(){
    levels['Q'] = 1;
    levels['A'] = 2;
    levels['W'] = 3;
    levels['S'] = 4;
    levels['E'] = 5;
    levels['D'] = 6;
    levels['R'] = 7;
    levels['F'] = 8;
    levels['T'] = 9;
    levels['G'] = 10;
    levels['Y'] = 11;
    levels['H'] = 12;
    levels['U'] = 13;
    levels['J'] = 14;


}

double sound_sin(double x, double a, double b){
    return a*sin(b*x);
}


void* start_aplay_worker(void* arg){
    can_play = false;
    std::string current_music_local = current_music;
    current_music = "";
    can_play = true;
    std::cout << "Calling : aplay " +current_music_local << std::endl;
    std::system(("aplay " + current_music_local).c_str());


}

void start_aplay_thread(){
    std::vector<std::vector<double>> points_new;
    for (double x = 10.0; x < 20.0; x += 0.05){
        points_new.push_back({x, sound_sin(x, mode_a, mode_b)});
    }
    for (const auto& point : points_new)
        points.push_back(point);
    points.push_back({20.0, 0.0});

    pthread_t tid; /* идентификатор потока */
    pthread_attr_t attr; /* отрибуты потока */

    /* получаем дефолтные значения атрибутов */
    pthread_attr_init(&attr);
    char* void_arg[0];
    //if (can_play)
    pthread_create(&tid,&attr, start_aplay_worker, void_arg);
}


void start_aplay(unsigned char key){
    int level = levels[(char)(toupper(key))];
    mode_b = level;


    //Draw();

    std::string file_name = "./data/data_" + std::to_string(mode_a) + '_' + std::to_string(level) + ".wav";
    current_music = file_name;

}


bool is_correct_key (unsigned char key) {
    // Q  A  W  S  E  D  R  F  T  G  Y  H  U  J
    std::string a = "QAWSEDRFTGYHUJ";
    for (char i : a){
        if (i == toupper(key))
            return true;
    }
    return false;

}


void key_pressed_callback(unsigned char key, int x, int y){
    switch (std::toupper(key)) {
        case 27: // ESC pressed
            exit(0);
        case '1':
            mode_a = 1;
            break;
        case '2':
            mode_a = 5;
            break;
        case '3':
            mode_a = 10;
            break;
        case '4':
            mode_a = 15;
            break;

        default:
            std::cout << "Pressed :" << key << " (" << (int)key << ")" << std::endl;
            if (is_correct_key(key))
                start_aplay(key);
            else {
                next_graphic_position();
                Draw();
            }
            break;

    }
}

int main( int argc, char *argv[] ) {


    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize( 800, 600 );
    glutInitWindowPosition( 100, 100 );
    glutCreateWindow( "OpenGL: Synthesizer" );
    //glutDisplayFunc( Draw );
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 0, 0);
    glutDisplayFunc(Draw);

    init();


    glutKeyboardUpFunc(key_pressed_callback);
    //glutMainLoop();
    while (run){
        points.push_back({10.0, 0.0});
        glutMainLoopEvent();
        Draw();
        next_graphic_position();
        if (can_play and current_music != "")
            start_aplay_thread();



    }
    return 0;
}