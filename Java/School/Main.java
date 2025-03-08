package school;

import school.students.Student;
import school.teachers.Teacher;

public class Main {
    public static void main(String[] args) {
        // Create objects of classes in different packages
        Student student = new Student();
        Teacher teacher = new Teacher();

        // Call display methods
        student.display();
        teacher.display();
    }
}
