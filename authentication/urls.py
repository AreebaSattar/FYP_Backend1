from django.contrib import admin
from django.urls import path, include
from . import views
urlpatterns=[
    path('',views.home, name="home"),
    path('signup',views.signup, name="signup"),
    path('signout',views.signout, name="signout"),
    path('api/signin/', views.signin, name='signin'),
    path('register',views.register_users, name="register_users"),
    path('changepass',views.change_pass, name="changepass"),
    #path('parsepdf',views.parsepdf, name="sentences"),    
    path('assign_role',views.assign_role, name="assign_role"),
    path('assign_role_person',views.assign_role_person, name="assign_role"),

    
    path('get_instructors',views.get_instructors, name="assign_role"),
    
    path('createuser',views.create_user, name="save_role"),
    path('deleteuser',views.delete_user, name="deleteuser"),
    path('saveroles',views.save_role, name="saverole"),
    path('save_data',views.save_data, name="saverole"),
    path('get_instructor_coursen',views.get_instructor_coursen, name="savaerole"),
    path('setSection',views.setSection,name='neg'),
    path('setCategory',views.setCategory,name='neg'),
    path('setinstructor',views.set_instructor, name="saverole"),
    path('getcourses',views.get_instructor_courses, name="saverole"),
    # path('getsemester',views.get_instructor_courses, name="saverole"),
    path('setcourse',views.setcourse, name="saverole"),
    path('registeredstudents', views.get_registered_students_json, name="assign_role_json"),
    path('feedbacksrec',views.feedbacksReceived,name ='feedbacks'),
    path('constcomment',views.Constructivecomments,name ='feedbacks'),
    path('negcom',views.negcomments,name='neg'),
    path('commentscategorywise',views.commentscategorywise,name='neg'),
    path('course_analysis',views.course_analysis,name='neg'),
    path('years_of_teacher',views.years_of_teacher,name='nefg'),
    path('feedback_saving',views.feedback_saving,name='nefg'),
    path('getcomments',views.getcomments,name='neg'),
    path('assigning',views.assigning,name='neg'),
    path('check_HOS',views.check_HOS,name='neg'),
    path('return_section',views.return_section,name='neg'), 
    path('category_wise',views.category_wise,name='neg'), 
    path('setFromDropdown',views.setFromDropdown,name='from'), 
    path('setToDropdown',views.setToDropdown,name='to'), 
    path('check_same_logged',views.check_same_logged,name='to'), 

    

    # course_analysis
# def commentscategorywise(request):
    
]