class EMPLOYEE {
    private String name;
    private int employeeID;
    public EMPLOYEE(String name, int employeeID) {
        this.name = name;
        this.employeeID = employeeID;
    }
    public void calculateSalary() {
    }
    public void displayEmployeeDetails() {
        System.out.println("Name: " + name);
        System.out.println("Employee ID: " + employeeID);
    }
}
class PartTimeEmp extends EMPLOYEE {
    private int hoursWorked;
    private static final double hourlyRate = 15.0;
    public PartTimeEmp(String name, int employeeID, int hoursWorked) {
        super(name, employeeID);
        this.hoursWorked = hoursWorked;
    }
    public void calculateSalary() {
        double salary = hoursWorked * hourlyRate;
        System.out.println("Salary: " + salary);
    }
    public void displayEmployeeDetails() {
        super.displayEmployeeDetails();
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Hourly Rate: " + hourlyRate);
    }
}
class FullTimeEmp extends EMPLOYEE {
    private double bonus;
    private double deductions;
    public FullTimeEmp(String name, int employeeID, double bonus, double deductions) {
        super(name, employeeID);
        this.bonus = bonus;
        this.deductions = deductions;
    }
    public void calculateSalary() {
        double baseSalary = 50000.0; // Full-time base salary (example value)
        double salary = baseSalary + bonus - deductions;
        System.out.println("Salary: " + salary);
    }
    public void displayEmployeeDetails() {
        super.displayEmployeeDetails();
        System.out.println("Bonus: " + bonus);
        System.out.println("Deductions: $" + deductions);
    }
}
class Main1 {
    public static void main(String[] args) {
        PartTimeEmp partTimeEmployee = new PartTimeEmp("Malhaar", 123, 20);
        FullTimeEmp fullTimeEmployee = new FullTimeEmp("Abcdef", 124, 5000.0, 1000.0);
        System.out.println("Part-Time Employee Details:");
        partTimeEmployee.displayEmployeeDetails();
        partTimeEmployee.calculateSalary();
        System.out.println("\nFull-Time Employee Details:");
        fullTimeEmployee.displayEmployeeDetails();
        fullTimeEmployee.calculateSalary();
    }
}
