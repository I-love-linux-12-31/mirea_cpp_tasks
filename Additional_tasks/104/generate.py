import sqlite3
# import random_name_generator.generators as rng
from mimesis import Person
from mimesis.enums import Gender

from random import choice, randint
from datetime import date

liters = "ЙЦУКЕНГШЩЗХФЫВАПРОЛДЖЭЯЧСМИТЮ"

fios = set()
person = Person("ru")
for i in range(15_000):
    fios.add(person.full_name(gender=Gender("male")))
    fios.add(person.full_name(gender=Gender("female")))

# print(*fios, sep="\n")
fios = list(fios)


def get_random_marks() -> str:
    res = ""
    for i in range(randint(6, 12)):
        res += choice("233444555555FPP")
    return res


groups_headers = [
    choice(liters) + choice(liters) + choice(liters) + choice(liters)
    for _ in range(16)
]


con = sqlite3.connect("students_lite.db")
cur = con.cursor()

# for student_id in range(1, 1536):
#     _name, _surname = fios[student_id].split()
#     _start_year = choice([2019, 2020, 2021, 2021, 2022, 2022, 2022])
#     _course = 2022 - _start_year + 1
#     _marks = ""
#     for _ in range(_course * 2 - 1):
#         _marks += get_random_marks() + "#"
#     _group = f"{choice(groups_headers)}-{randint(0, 8)}-{_start_year % 100}"
#     _birthday = date(randint(1997, 2006), randint(1, 12), randint(1, 28))
#     print(student_id, _name, _surname, _course, _group, _marks, _birthday)
#     req = f'INSERT INTO students VALUES({student_id}, "{_name}", "{_surname}", NULL, {_course}, "{_group}", "{_marks}", {_start_year}, "{_birthday}")'
#     cur.execute(req)


student_id = -1
for _start_year in [2019, 2020, 2021, 2021, 2022, 2022, 2022]:
    for _group_name in groups_headers:
        for _group_index in range(randint(2, 13)):
            for i in range(randint(15, 30)):
                student_id += 1
                _name, _surname = fios[student_id].split()
                _course = 2022 - _start_year + 1
                _marks = ""
                for _ in range(_course * 2 - 1):
                    _marks += get_random_marks() + "#"
                _group = f"{choice(groups_headers)}-{_group_index}-{_start_year % 100}"
                _birthday = date(randint(1997, 2006), randint(1, 12), randint(1, 28))
                print(student_id, _name, _surname, _course, _group, _marks, _birthday)
                req = f'INSERT INTO students VALUES({student_id}, "{_name}", "{_surname}", NULL, {_course}, "{_group}", "{_marks}", {_start_year}, "{_birthday}")'
                cur.execute(req)




con.commit()
