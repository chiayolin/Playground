class Human {
    /* Things humans share as a group */
    public static enum Genders { MALE, FEMALE };
    public static int population = 1000;

    /* Specific to that individual */
    public Genders gender;

    /* constructors */
    public Human() {
        this.population += 1;
    }
}

class Person extends Human {
    public String name;

    public Person(String name) {
        this.name = name;
    }
}

public class HumanTest {
    public static void main(String args[]) {
        System.out.println("There are " + Person.population + " Humans");
        System.out.println("Creating a Bob...");
        Human bob = new Person("Bob");
        System.out.println("There are " + Person.population + " Humans");
        bob.gender = Person.Genders.MALE;
        System.out.println("The gender of Bob is " + bob.gender);
    }
} 
