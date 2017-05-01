class Person {
    private String firstName; 
    private String lastName;

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFirstName() {
        return this.firstName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public String getFullName() {
        /*
         * Below is an exmaple of how to write: 
         *
         *      return this.firstName + " " + this.lastName;
         *
         * without the syntactic sugar for concatenating.
         *
         * */
        return this.firstName.concat(" ").concat(this.lastName);
    }

    public Person(String firstName, String lastName) {
        setFirstName(firstName);
        setLastName(lastName);
    }
}

public class Chaining {
    public static void main(String args[]) {
        Person dylan = new Person("Bob", "Dylan");
        System.out.println(dylan.getFullName());
    }
}
