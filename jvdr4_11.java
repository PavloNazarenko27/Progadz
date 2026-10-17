import java.util.ArrayList;
import java.util.List;

public class Main {
    static class Department {
        private String name;
        private List<Position> positions = new ArrayList<>();

        public Department(String name) {
            this.name = name;
        }

        class Position {
            private String title;
            private List<String> employeesHistory = new ArrayList<>();

            public Position(String title) {
                this.title = title;
            }

            public void addEmployee(String employeeName) {
                employeesHistory.add(employeeName);
            }

            public void printHistory() {
                System.out.println("Посада: " + title);
                System.out.println("Співробітники, які займали посаду:");
                for (String emp : employeesHistory) {
                    System.out.println("- " + emp);
                }
            }
        }

        public Position createPosition(String title) {
            Position pos = new Position(title);
            positions.add(pos);
            return pos;
        }

        public void printDepartmentInfo() {
            System.out.println("Відділ: " + name);
            for (Position pos : positions) {
                pos.printHistory();
            }
        }
    }

    public static void main(String[] args) {
        Department dept = new Department("Розробка");
        
        Department.Position dev = dept.createPosition("Lead Developer");
        dev.addEmployee("Іванов І.І.");
        dev.addEmployee("Сидоров С.С.");

        Department.Position qa = dept.createPosition("QA Engineer");
        qa.addEmployee("Петров П.П.");

        dept.printDepartmentInfo();
    }
}