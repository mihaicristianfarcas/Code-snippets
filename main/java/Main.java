import Controller.MyController;
import Repository.MyFileRepository;
import Repository.MyIRepository;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.function.Consumer;

// TODO: modify grid pane, make one step work, study project through
public class Main extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        MyIRepository repository = new MyFileRepository("logGUI.txt");
        MyController controller = new MyController(repository);

        FXMLLoader mainWindowLoader = new FXMLLoader();
        mainWindowLoader.setLocation(getClass().getResource("mainWindow.fxml"));
        mainWindowLoader.setControllerFactory(c -> new MainWindowController(controller));

        Parent mainWindowRoot = mainWindowLoader.load();
        MainWindowController mainWindowController = mainWindowLoader.getController();

        stage.setTitle("Main Window");
        stage.setScene(new Scene(mainWindowRoot));
        stage.show();

        Stage secondaryStage = new Stage();
        FXMLLoader setProgramLoader = new FXMLLoader();

        setProgramLoader.setControllerFactory(c -> new ProgramsWindowController(controller, mainWindowController));
        setProgramLoader.setLocation(getClass().getResource("programsWindow.fxml"));

        Parent setProgramRoot = setProgramLoader.load();
        ProgramsWindowController setProgramController = setProgramLoader.getController();

        secondaryStage.setTitle("Programs Window");
        secondaryStage.setScene(new Scene(setProgramRoot));
        secondaryStage.show();


//        FXMLLoader programsWindowLoader = new FXMLLoader(Main.class.getResource("programsWindow.fxml"));
//        Scene programsScene = new Scene(programsWindowLoader.load(), 320, 240);
//        programsStage.setTitle("Programs Window");
//        programsStage.setScene(programsScene);
//        programsStage.show();
//
//        Stage mainStage = new Stage();
//        FXMLLoader mainWindowLoader = new FXMLLoader(Main.class.getResource("mainWindow.fxml"));
//        Scene mainScene = new Scene(mainWindowLoader.load(), 320, 240);
//        mainStage.setTitle("Main Window");
//        mainStage.setScene(mainScene);
//        mainStage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}