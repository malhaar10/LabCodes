class Building {
    private double squareFootage;
    private int stories;
    public Building(double squareFootage, int stories) {
        this.squareFootage = squareFootage;
        this.stories = stories;
    }
    public double getSquareFootage() {
        return squareFootage;
    }
    public void setSquareFootage(double squareFootage) {
        this.squareFootage = squareFootage;
    }
    public int getStories() {
        return stories;
    }
    public void setStories(int stories) {
        this.stories = stories;
    }
}
class House extends Building {
    private int bedrooms;
    private int baths;
    public House(double squareFootage, int stories, int bedrooms, int baths) {
        super(squareFootage, stories);
        this.bedrooms = bedrooms;
        this.baths = baths;
    }
    public int getBedrooms() {
        return bedrooms;
    }
    public void setBedrooms(int bedrooms) {
        this.bedrooms = bedrooms;
    }
    public int getBaths() {
        return baths;
    }
    public void setBaths(int baths) {
        this.baths = baths;
    }
}
class School extends Building {
    private int classrooms;
    private String gradeLevel;
    public School(double squareFootage, int stories, int classrooms, String gradeLevel) {
        super(squareFootage, stories);
        this.classrooms = classrooms;
        this.gradeLevel = gradeLevel;
    }
    public int getClassrooms() {
        return classrooms;
    }
    public void setClassrooms(int classrooms) {
        this.classrooms = classrooms;
    }
    public String getGradeLevel() {
        return gradeLevel;
    }
    public void setGradeLevel(String gradeLevel) {
        this.gradeLevel = gradeLevel;
    }
}
class Home{
    public static void main(String[] args) {
        Building building = new Building(2000, 3);
        House house = new House(1500, 2, 3, 2);
        School school = new School(5000, 2, 20, "Elementary");
        System.out.println("Building Details:");
        System.out.println("Square Footage: " + building.getSquareFootage());
        System.out.println("Stories: " + building.getStories());
        System.out.println("\nHouse Details:");
        System.out.println("Square Footage: " + house.getSquareFootage());
        System.out.println("Stories: " + house.getStories());
        System.out.println("Bedrooms: " + house.getBedrooms());
        System.out.println("Baths: " + house.getBaths());
        System.out.println("\nSchool Details:");
        System.out.println("Square Footage: " + school.getSquareFootage());
        System.out.println("Stories: " + school.getStories());
        System.out.println("Classrooms: " + school.getClassrooms());
        System.out.println("Grade Level: " + school.getGradeLevel());
    }
}
