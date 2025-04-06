import java.util.Scanner;
import java.util.TreeMap;

class Key {
    int d1;
    int d2;
    int d3;
    int d4;

    public Key(int d1, int d2, int d3, int d4) {
        this.d1 = d1;
        this.d2 = d2;
        this.d3 = d3;
        this.d4 = d4;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(d1) * 31 * 31 * 31 + Integer.hashCode(d2) * 31 * 31 + Integer.hashCode(d3) * 31 + Integer.hashCode(d4);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Key key = (Key) obj;
        return d1 == key.d1 && d2 == key.d2 && d3 == key.d3 && d4 == key.d4;
    }
}
