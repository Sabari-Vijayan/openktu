class Employee 
{ 
    String name; 
    int age; 
    String phoneNumber; 
    String address; 
    float salary; 
    public Employee(String name, int age, String phoneNumber, String address, float salary) 
    { 
        this.name = name; 
        this.age = age; 
        this.phoneNumber = phoneNumber; 
        this.address = address; 
        this.salary = salary; 
    } 
 
    public void printSalary()  
    { 
        System.out.println("Salary: " + salary); 
    } 
 
    public void displayDetails()  
    { 
        System.out.println("Name: " + name); 
        System.out.println("Age: " + age); 
        System.out.println("Phone Number: " + phoneNumber); 
        System.out.println("Address: " + address); 
    } 
} 
 
class Officer extends Employee  
{ 
    String specialization; 
    public Officer(String name, int age, String phoneNumber, String address, float salary,       
String specialization)  
    { 
        super(name, age, phoneNumber, address, salary); 
        this.specialization = specialization; 
    } 
    public void displayDetails()  
    { 
        super.displayDetails(); 
        System.out.println("Specialization: " + specialization); 
        printSalary(); 
    } 
} 
 
class Manager extends Employee  
{ 
    String department; 
    public Manager(String name, int age, String phoneNumber, String address, float salary, 
String department)  
    { 
        super(name, age, phoneNumber, address, salary); 
        this.department = department; 
    } 
    public void displayDetails()  
    { 
        super.displayDetails(); 
        System.out.println("Department: " + department); 
        printSalary(); 
    } 
} 
 
public class EmployeeInheritance  
{ 
    public static void main(String[] args)  
    { 
        Officer officer = new Officer("Andrew Jerry", 19, "1234567890", "Pala", 55000, "Programmer"); 
        Manager manager = new Manager("John Wick", 22, "0987654321", "Kottayam", 75000, "Human Resources"); 
        System.out.println("Officer Details:"); 
        officer.displayDetails(); 
        System.out.println("\nManager Details:"); 
        manager.displayDetails(); 
    } 
} 
