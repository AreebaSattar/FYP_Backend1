from django.db import models
# models.py

from django.contrib.auth.models import AbstractUser
from django.db import models

class Teacher(AbstractUser):
    teacher_id = models.AutoField(primary_key=True)
    # Add any other custom fields you need for the Teacher model
    teacher_roll_number= models.CharField(max_length=7 ,default='0000000')
    def __str__(self):
        return self.username

# Create your models here.
from django.db import models

class Course(models.Model):
    course_id = models.AutoField(primary_key=True, unique=True)
    course_name = models.CharField(max_length=255)
    course_code=models.CharField(max_length=255, default='')
    # Add any other fields for the Course model

    def __str__(self):
        return self.course_name
# models.py

class TeacherCourse(models.Model):
    id = models.AutoField(primary_key=True)
   
    teacher = models.ForeignKey(Teacher, on_delete=models.CASCADE)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)

    def __str__(self):
        return f"{self.teacher.username} - {self.course.course_name}"
    


class Section(models.Model):
    id = models.AutoField(primary_key=True)
    teacher_course = models.ForeignKey(TeacherCourse, on_delete=models.CASCADE)
    section_name = models.CharField(max_length=255)
    semester = models.CharField(max_length=50)
    year = models.CharField(max_length=50, default='')
    registered_students = models.PositiveIntegerField(default=0)
    feedbacks_received = models.PositiveIntegerField(default=0)
    number_of_positive_comments=models.PositiveIntegerField(default=0)
    number_of_constructive_comments=models.PositiveIntegerField(default=0)
    number_of_positive_comments_ass=models.PositiveIntegerField(default=0)
    number_of_positive_comments_content_org=models.PositiveIntegerField(default=0)
    number_of_positive_comments_learning_mat=models.PositiveIntegerField(default=0)
    number_of_positive_comments_classenv=models.PositiveIntegerField(default=0)


    def __str__(self):
        return f"{self.teacher_course} - {self.section_name} - {self.semester}"
class Comment(models.Model):
    id = models.AutoField(primary_key=True)
    section = models.ForeignKey(Section, on_delete=models.CASCADE)
    comments = models.CharField(max_length=1000,default="")  # Adjust the max_length as needed
    category=models.CharField(max_length=1000,default="")

    def __str__(self):
        return f"Comment #{self.id} - Section: {self.section.section_name}, Semester: {self.section.semester}"
    

class Respon(models.Model):
    id = models.AutoField(primary_key=True)
    section = models.ForeignKey(Section, on_delete=models.CASCADE)
    respon= models.CharField(max_length=1000,default="")  # Adjust the max_length as needed
    category=models.CharField(max_length=1000,default="")

    def __str__(self):
        return f"Comment #{self.id} - Section: {self.section.section_name}, Semester: {self.section.semester}"