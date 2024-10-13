from Student import Student


student1=Student("John",20,)

student1.add_grade("Math",5)
student1.add_grade("Science",6)
student1.add_grade("Biology",6)

print(student1.get_info())
print(student1.get_grades())