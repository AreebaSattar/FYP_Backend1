# Generated by Django 4.2.6 on 2023-12-12 13:32

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('PDF_processing', '0003_course_course_code_and_more'),
    ]

    operations = [
        migrations.AddField(
            model_name='comment',
            name='category',
            field=models.CharField(default='', max_length=1000),
        ),
        migrations.AlterField(
            model_name='comment',
            name='comments',
            field=models.CharField(default='', max_length=1000),
        ),
    ]
