import java.util.*;

public class RevenueCalculatorNoStreams {
    // Order class to hold each order’s data
    static class Order {
        private final String productName;
        private final String region;
        private final int quantity;
        private final double unitPrice;

        public Order(String productName, String region, int quantity, double unitPrice) {
            this.productName = productName;
            this.region      = region;
            this.quantity    = quantity;
            this.unitPrice   = unitPrice;
        }

        public String getProductName() { return productName; }
        public String getRegion()      { return region; }
        public int    getQuantity()    { return quantity; }
        public double getUnitPrice()   { return unitPrice; }
    }

    public static void main(String[] args) {
        // Sample data (including one non-US order to show filtering)
        List<Order> orders = Arrays.asList(
            new Order("Headphones", "US", 5,   100.0),
            new Order("Laptop",     "US", 2,  1500.0),
            new Order("Laptop",     "US", 1,   550.0),
            new Order("Smartphone", "US", 6,   410.0),
            new Order("Headphones", "EU", 3,   100.0)  // will be ignored
        );

        // Use a TreeMap so that the keys (product names) stay sorted alphabetically
        Map<String, Double> revenueByProduct = new TreeMap<>(Comparator.reverseOrder());
        List<Map.Entry<String,Double>> revenueEntries = new ArrayList<>();

        // 1) Filter to US region and 2) accumulate revenue per product
        for (Order o : orders) {
            if (!"US".equals(o.getRegion())) {
                continue;
            }
            double revenue = o.getQuantity() * o.getUnitPrice();
            String product = o.getProductName();
            // accumulate
            revenueByProduct.put(
                product,
                revenueByProduct.getOrDefault(product, 0.0) + revenue
            );
        }

        // 3) Print each product & total revenue, formatted with commas and two decimals
        for (Map.Entry<String, Double> entry : revenueByProduct.entrySet()) {
            String product = entry.getKey();
            double rev    = entry.getValue();
            System.out.printf("%-12s -> $%,.2f%n", product, rev);
        }
    }
}
