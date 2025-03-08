
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class CreateFile {

    public static void main(String[] args) {

        // Create File
        try {
            File file = new File("myfile.txt");
            if (file.createNewFile()) {
                System.out.println("File is Created " + file.getName());
            } else {
                System.out.println("File already Exits");
            }

        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("An Error Occured");
            e.printStackTrace();
        }


        // Write into the File
        try {
            FileWriter writer = new FileWriter("myfile.txt");
            writer.write("Hello This the content of the file ");
            writer.close();
            System.out.println("Successfully wrote to the file ");
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("An Error Occured");
            e.printStackTrace();
        }


        // Read File using BufferReader
        try {
            FileReader reader = new FileReader("myfile.txt");
            BufferedReader bufferedReader = new BufferedReader(reader);
            String line;
            if ((line = bufferedReader.readLine()) != null) {
                System.out.println(line);
            } else {
                System.out.println("No contents yet");
            }
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("An Error Occured");
            e.printStackTrace();

        }


        // Delete File 
        try {
            File myFile = new File("myfile.txt");
            if (myFile.delete()) {
                System.out.println("File deleted: " + myFile.getName());
            } else {
                System.out.println("Failed to delete the file.");
            }

        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("An Error Occured");
            e.printStackTrace();
        }


        // Read File using Scanner 
        try {
            File myfile = new File("myfile.txt");
            Scanner scanner = new Scanner(myfile);
            while(scanner.hasNextLine()){
                String line = scanner.nextLine();
                System.out.println(line);
            }
            scanner.close();

        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("An Error Occured");
            e.printStackTrace();
        }


    }
}
