from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group

class Command(BaseCommand):
    help = 'Create custom groups (roles)'

    def handle(self, *args, **options):
        instructor_group, created = Group.objects.get_or_create(name='Instructor')
        hod_cs_group, created = Group.objects.get_or_create(name='HOD CS')
        hod_fsm_group, created = Group.objects.get_or_create(name='HOD FSM')
        self.stdout.write(self.style.SUCCESS('Custom groups created'))
