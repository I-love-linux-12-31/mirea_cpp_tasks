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
    for i in range(randint(6, 16)):
        res += choice("2345FP")
    return res


groups_headers = [
    choice(liters) + choice(liters) + choice(liters) + choice(liters)
    for _ in range(128)
]


con = sqlite3.connect("students")
cur = con.cursor()

for student_id in range(1, 10_000):
    _name, _surname = fios[student_id].split()
    _start_year = randint(2019, 2022)
    _course = 2022 - _start_year + 1
    _marks = ""
    for _ in range(_course * 2 - 1):
        _marks += get_random_marks() + "#"
    _group = f"{choice(groups_headers)}-{randint(0, 32)}-{_start_year % 100}"
    _birthday = date(randint(1997, 2006), randint(1, 12), randint(1, 28))
    print(student_id, _name, _surname, _course, _group, _marks, _birthday)
    req = f'INSERT INTO students VALUES({student_id}, "{_name}", "{_surname}", NULL, {_course}, "{_group}", "{_marks}", {_start_year}, "{_birthday}")'
    cur.execute(req)

con.commit()
