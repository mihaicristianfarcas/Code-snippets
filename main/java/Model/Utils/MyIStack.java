package Model.Utils;

import java.util.List;

public interface MyIStack<T> {
    void push(T v);
    T pop();
    boolean isEmpty();
    String toString();
    T top();
    int size();
    void clear();
    Iterable<T> getAll();
}
