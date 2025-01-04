import Controller.MyController;
import Model.Statements.IStmt;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;

import View.HardcodedPrograms;

import java.util.List;

public class ProgramsWindowController {
    MyController controller;
    MainWindowController mainWindowController;

    public ProgramsWindowController(MyController controller, MainWindowController mainWindowController) {
        this.controller = controller;
        this.mainWindowController = mainWindowController;
    }

    @FXML
    private ListView<IStmt> programsList;

    @FXML
    private Button pickedProgramButton;

    @FXML
    public void initialize() {
        List<IStmt> programs = HardcodedPrograms.getPrograms();
        programsList.setItems(FXCollections.observableList(programs));
        pickedProgramButton.setOnAction(actionEvent -> {
            try {
                int index = programsList.getSelectionModel().getSelectedIndex();
                if (index < 0) {
                    System.out.println("No index selected");
                } else if (index >= programs.size()) {
                    System.out.println("No program at selected index");
                } else {
                    System.out.println("Selected program " + index);
                }
                controller.setProgram(programs.get(index));
                mainWindowController.refresh();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        });
        mainWindowController.refresh();
    }
}