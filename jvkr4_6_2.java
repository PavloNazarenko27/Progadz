package pack2;

import pack1.TaskClass;

public class Main {
    public static void main(String[] args) {
        TaskClass obj = new TaskClass();
        // obj.protectedMethod(); // Помилка: protected недоступний поза пакетом без спадкування
    }
}