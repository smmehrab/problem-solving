package sample;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class PageManager extends Application {


    Stage window;
    Scene loginScene;
    Scene signupScene;

    @Override
    public void start(Stage primaryStage) {

        String username=null;
        String password=null;

        window=primaryStage;
        window.setTitle("SET THE DESK");

        GridPane grid=new GridPane();
        grid.setPadding(new Insets(20,20,20,20));
        grid.setVgap(10);
        grid.setHgap(10);
        GridPane.setConstraints(grid, 0, 0);

        // NAme Label
        Label usernameLabel=new Label("UserName");

        //Name Input
        TextField usernameInput=new TextField();
        usernameInput.setPromptText("Enter Your Username");

        GridPane.setConstraints(usernameInput, 1, 0);


        Label passwordLabel= new Label("Password");

        TextField passwordInput=new TextField();
        passwordInput.setPromptText("Password");

        password=passwordInput.getText();

        Label notUserLabel=new Label("New User? ");

        GridPane.setConstraints(passwordLabel, 0, 1);
        GridPane.setConstraints(passInput, 1, 1);
        GridPane.setConstraints(notUserLabel, 1, 4);


        Button newlogin=new Button("Sign up");
        Button login=new Button("Login");
        GridPane.setConstraints(newlogin, 2, 4);
        GridPane.setConstraints(login, 1, 2);
        grid.getChildren().addAll(nameLabel,nameInput,passLabel,passInput,newlogin,login,notUserLabel);


        username=usernameInput.getText();

        newlogin.setOnAction(new EventHandler<ActionEvent>() {


            @Override
            public void handle(ActionEvent event) {
                GridPane grid2=new GridPane();
                grid2.setPadding(new Insets(20,20,20,20));
                grid2.setVgap(10);
                grid2.setHgap(10);
                signupScene=new Scene(grid2,400,300);
                window.setScene(signupScene);
                // NAme Label
                Label nameLabel2=new Label("UserName");
                GridPane.setConstraints(grid2, 10, 10);
                //Name Input
                TextField nameInput2=new TextField();
                GridPane.setConstraints(nameInput2, 1, 0);
                nameInput.setPromptText("Username");
                Label passLabel2=new Label("Password");
                GridPane.setConstraints(passLabel2, 0, 1);
                TextField passInput2=new TextField();
                passInput2.setPromptText("Password");
                GridPane.setConstraints(passInput2, 1, 1);
                Label signedUp2=new Label("Already SignedUp?");
                GridPane.setConstraints(signedUp2, 1, 4);
                Button signIn2=new Button("Sign in");
                GridPane.setConstraints(signIn2, 2, 4);
                Button signUp2=new Button("Sign Up");
                GridPane.setConstraints(signUp2, 1, 3);
                grid2.getChildren().addAll(nameLabel2,nameInput2,passLabel2,passInput2,signedUp2,signIn2,signUp2);
                signIn2.setOnAction(new EventHandler<ActionEvent>() {

                    @Override
                    public void handle(ActionEvent event) {
                        window.setScene(loginScene);
                    }
                });
                signUp2.setOnAction(new EventHandler<ActionEvent>() {

                    @Override
                    public void handle(ActionEvent event) {
                        String userName2=nameInput2.getText();
                        String password2=passInput2.getText();
                        System.out.println(password2);
                        System.out.println(userName2);
                        try {
                            fileHandler(userName2,password2);
                        } catch (IOException ex) {
                            System.out.println(ex);
                        }
                    }
                });

            }


        });
        login.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                String userName=nameInput.getText();
                String password=passInput.getText();
                System.out.println(password);
                System.out.println(userName);
                try {
                    fileSignIn(userName,password);
                } catch (IOException ex) {
                    System.out.println(ex);
                }
            }


        });
        loginScene=new Scene(grid,400,300);
        window.setScene(loginScene);
        window.show();
    }
    private void fileHandler(String userName, String password) throws FileNotFoundException, IOException {


        String newLine="\n";
        String space=" ";
        boolean f=false;

        try (Scanner scanner = new Scanner(new File("C:/Users/ASUS/Documents/NetBeansProjects/Tutorial5/src/tutorial5/file1.txt"))) {

            try{
                while(scanner.hasNextLine()){
                    String scanner1=scanner.next();
                    String scanner2=scanner.next();
                    if(scanner1.equals(userName) && scanner2.equals(password)){
                        f=true;
                        break;
                    }
                }
                if(f)System.out.println("Choose a different email ID");
            }catch(Exception e){
                f=false;
            }
            //  System.out.println(scanner.next());

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        if(f==false){
            File file=new File("C:/Users/ASUS/Documents/NetBeansProjects/Tutorial5/src/tutorial5/file1.txt");
            StringBuilder sb=new StringBuilder();
            sb.append("\n"+userName+" "+password+"\n");
            FileWriter w=new FileWriter(file,true);
            w.write(sb.toString());
            w.close();
        }




    }
    private void fileSignIn(String userName, String password) throws FileNotFoundException, IOException {


        String newLine="\n";
        String space=" ";
        boolean f=false;
        //File file=new File("C:/Users/ASUS/Documents/NetBeansProjects/Tutorial5/src/tutorial5/file1.txt");
        try (Scanner scanner = new Scanner(new File("C:/Users/ASUS/Documents/NetBeansProjects/Tutorial5/src/tutorial5/file1.txt"))) {

            try{
                while(scanner.hasNextLine()){
                    String scanner1=scanner.next();
                    String scanner2=scanner.next();
                    if(scanner1.equals(userName) && scanner2.equals(password)){
                        f=true;
                        break;
                    }
                }
                if(f)System.out.println("Sign in successful.");
            }catch(Exception e){
                System.out.println("Invalid Username or Password.");
            }
            //  System.out.println(scanner.next());

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }


    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
