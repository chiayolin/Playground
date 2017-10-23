import java.util.*;
import java.util.function.*;

class NumberMatrix {
    /* `static` means that it's shared by all instances */ 
    private static final int adj_length = 13;
    
    public static final String[] matrix = {
            "73167176531330624919225119674426574742355349194934",
            "96983520312774506326239578318016984801869478851843",
            "85861560789112949495459501737958331952853208805511",
            "12540698747158523863050715693290963295227443043557",
            "66896648950445244523161731856403098711121722383113",
            "62229893423380308135336276614282806444486645238749",
            "30358907296290491560440772390713810515859307960866",
            "70172427121883998797908792274921901699720888093776",
            "65727333001053367881220235421809751254540594752243",
            "52584907711670556013604839586446706324415722155397",
            "53697817977846174064955149290862569321978468622482",
            "83972241375657056057490261407972968652414535100474",
            "82166370484403199890008895243450658541227588666881",
            "16427171479924442928230863465674813919123162824586",
            "17866458359124566529476545682848912883142607690042",
            "24219022671055626321111109370544217506941658960408",
            "07198403850962455444362981230987879927244284909188",
            "84580156166097919133875499200524063689912560717606",
            "05886116467109405077541002256983155200055935729725",
            "71636269561882670428252483600823257530420752963450" 
        };
    
    private double largestAdjProduct() {
        double total_list[] = new double[100000];
        
        int counter = 0;
        for(String row : this.matrix) {
            for(int c = 0; c != this.matrix[0].length(); c++) {
                ArrayList<Integer> adj_list = new ArrayList<Integer>();
                double adj_product = 1;

                for(int col = 0; col != this.adj_length && 
                    col + c + this.adj_length <= this.matrix[0].length(); col++)
                        adj_list.add(Integer.parseInt(String.valueOf(
                            row.charAt(col + c))));
               
                for(double element : adj_list) 
                    adj_product *= element;

                total_list[counter++] = adj_product;
            }
        }
    
        double doubleest = 0;
        for(double element : total_list) {
            if(element >= doubleest) {
                doubleest = element;
            }
        }

        return doubleest;

    }
    
    private double largestVerProduct() {
        int row_offset, col_offset, counter;
        row_offset = col_offset = counter = 0;
        
        double[] total_segment = new double[10000];
        while(row_offset + this.adj_length <= this.matrix.length) {
            for(int col = 0; col != this.matrix[0].length(); col++) {
                int[] vertical_segment = new int[this.adj_length];
                for(int row = 0; row != this.adj_length && 
                    row + row_offset <= this.matrix.length; row++) {
                        vertical_segment[row] = Integer.parseInt(String.valueOf(
                            this.matrix[row + row_offset].charAt(col)));
                }
                
                double segment_product = 1;
                for(int element : vertical_segment) {
                    segment_product *= element;
                }

                total_segment[counter++] = segment_product;
            }
            
            row_offset++;
        }
        
        double doubleest = 0;
        for(double element : total_segment) {
            if(element >= doubleest) 
                doubleest = element;

            //System.out.println("e: " + element);
        }

        return doubleest;
    }


    private double rightAdjProduct(final int row, final int col) {
        ArrayList<Integer> adj_list = new ArrayList<Integer>();
        double adj_product = 1;
        
        if(row + this.adj_length > this.matrix.length ||
            col + this.adj_length > this.matrix[row].length())
                return 0;
        
        for(int offset = 0; offset != this.adj_length; offset++)
            adj_list.add(Integer.parseInt(String.valueOf(
                this.matrix[row + offset].charAt(col + offset))));
        
        for(int element : adj_list)
           adj_product *= element;

        return adj_product;
    }
    
    private double leftAdjProduct(final int row, final int col) {
        ArrayList<Integer> adj_list = new ArrayList<Integer>();
        double adj_product = 1;
        
        if(row + this.adj_length > this.matrix.length || 
            (col + 1) - this.adj_length < 0) 
                return 0;
        
        for(int offset = 0; offset != this.adj_length; offset++)
            adj_list.add(Integer.parseInt(String.valueOf(
                this.matrix[row + offset].charAt(col - offset))));
        
        for(int element : adj_list)
           adj_product *= element;

        return adj_product;
    }

    private double largestProductOf(String side) {
        double largest_product, current_product;
        largest_product = current_product = 0;
        for(int row = 0; row < this.matrix.length; row++) {
            for(int col = 0; col < this.matrix[row].length(); col++) {
                current_product = side.equals("right") ? 
                    rightAdjProduct(row, col) : leftAdjProduct(row, col);
                if(largest_product <= current_product) 
                    largest_product = current_product;
            }
        }

        return largest_product;
        
    }

    public double findLargestProduct() {
        double largest_left_adj = largestProductOf("left"); 
        double largest_right_adj = largestProductOf("right");
        double largest_adj_product = largestAdjProduct();
        System.out.println("hor: " + largest_adj_product);
        System.out.println("ver: " + largestVerProduct());
        if(largest_left_adj < largest_right_adj)
            return largest_right_adj;
        return largest_left_adj;
    }

    public NumberMatrix() {

    } 
}

public class FindLargestProduct {
    public static void main(String[] args) {
        NumberMatrix matrix = new NumberMatrix();
        double largest_product = matrix.findLargestProduct();

        System.out.println("adj: " + largest_product);
    }
}
