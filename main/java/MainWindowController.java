import Controller.MyController;
import Model.PrgState;
import Model.Statements.IStmt;
import Model.Utils.MyIDictionary;
import Model.Utils.MyIHeap;
import Model.Utils.MyIList;
import Model.Values.StringValue;
import Model.Values.Value;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.util.Pair;

import java.io.BufferedReader;
import java.util.NoSuchElementException;

public class MainWindowController {
private final MyController controller;
private MyIHeap<Value> heap;
private MyIDictionary<StringValue, BufferedReader> fileTable;
private MyIList<Value> output;

// TODO study this class and maybe improve it
public MainWindowController(MyController controller) {
    this.controller = controller;
}

    @FXML
    private Label programStatesLabel;

    @FXML
    private ListView<Integer> programStatesListView;

    @FXML
    private ListView<IStmt> executionStackListView;

    @FXML
    private ListView<String> fileTableListView;

    @FXML
    private ListView<String> outListView;

    @FXML
    private TableView<Pair<Integer, Value>> heapTableTableView;

    @FXML
    private TableColumn<Pair<Integer, Value>, Integer> heapAddressesColumn;

    @FXML
    private TableColumn<Pair<Integer, Value>, String> heapValuesColumn;

    @FXML
    private TableView<Pair<String, Value>> symbolTableTableView;

    @FXML
    private TableColumn<Pair<String, Value>, String> symbolNameColumn;

    @FXML
    private TableColumn<Pair<String, Value>, String> symbolValueColumn;

    @FXML
    private Button runButton;

    @FXML
    private Button oneStepButton;

    public void refresh() {
        Integer selectedProgramId = programStatesListView.getSelectionModel().getSelectedItem();
        programStatesListView.getItems().clear();
        heapTableTableView.getItems().clear();
        outListView.getItems().clear();
        fileTableListView.getItems().clear();
        symbolTableTableView.getItems().clear();
        executionStackListView.getItems().clear();

        programStatesLabel.setText("Program states: " + controller.getPrgStates().size());
        controller.getPrgStates().forEach(prgState -> programStatesListView.getItems().add(prgState.getCurrentID()));

        if (!controller.getPrgStates().isEmpty()) {
            heap = controller.getPrgStates().get(0).getHeap();
            output = controller.getPrgStates().get(0).getOut();
            fileTable = controller.getPrgStates().get(0).getFileTable();

        }

        if (heap != null) {
            heap.getContent().forEach((K, V) -> heapTableTableView.getItems().add(new Pair<>(K, V)));
        }

        if (output != null) {
            output.getAll().forEach(output -> outListView.getItems().add(output.toString()));
        }

        if (fileTable != null) {
            fileTable.getContent().forEach((K, V) -> fileTableListView.getItems().add(K.toString()));
        }

        PrgState current;
        try {
            current = controller.getPrgStates().stream().filter(x -> x.getCurrentID().equals(selectedProgramId)).findAny().get();
            current.getSymTable().getContent().forEach((K, V) -> symbolTableTableView.getItems().add(new Pair<>(K, V)));
            Iterable<IStmt> statementList = current.getExeStack().getAll();
            for (IStmt stmt : statementList) {
                executionStackListView.getItems().add(stmt);
            }
            programStatesListView.getSelectionModel().select(selectedProgramId);
        } catch (NoSuchElementException ignored) {
        } finally {
            programStatesListView.refresh();
            heapTableTableView.refresh();
            outListView.refresh();
            fileTableListView.refresh();
            symbolTableTableView.refresh();
            executionStackListView.refresh();
        }
    }

    @FXML
    public void initialize() {
        this.heapAddressesColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        this.heapValuesColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().toString()));
        this.symbolNameColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getKey()));
        this.symbolValueColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().toString()));
        this.refresh();

        this.oneStepButton.setOnAction(actionEvent -> {
            try {
                this.controller.oneStepForAllPrg(controller.getPrgStates());
            } catch (Exception e) {
                Alert alert = new Alert(Alert.AlertType.ERROR, e.getMessage());
                alert.show();
            }
            this.refresh();
        });

        this.runButton.setOnAction(actionEvent -> {
            try {
                controller.allStep();
            } catch (Exception e) {
                Alert alert = new Alert(Alert.AlertType.ERROR, e.getMessage());
                alert.show();
            }
            this.refresh();
        });
        this.programStatesListView.setOnMouseClicked(x -> this.refresh());
    }
}
