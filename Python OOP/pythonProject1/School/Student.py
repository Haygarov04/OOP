from Grades import Grade

class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.grades = []  # Списък от оценки (обекти от клас Grade)

    def add_grade(self, subject, value):
        grade = Grade(subject, value)
        self.grades.append(grade)

    def get_info(self):
        return f"Student Name: {self.name}, Age: {self.age}"

    def get_grades(self):
        if not self.grades:
            return "No grades available."
        return [grade.get_grade_info() for grade in self.grades]
