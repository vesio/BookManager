package courseDesign;

import java.awt.Component;  
import java.awt.Font;  
import java.awt.event.ActionEvent;  
import java.awt.event.ActionListener;  
  
import javax.swing.JButton;  
import javax.swing.JDialog;  
import javax.swing.JLabel;  
import javax.swing.JSpinner;  
import javax.swing.JTextField;  
import javax.swing.SpinnerModel;  
import javax.swing.SpinnerNumberModel;  
import javax.swing.UIManager;  
  
 
@SuppressWarnings("serial")  
public class AddBookDialog extends JDialog {  
    private static String[] str = {"书名","编号","价格"};  
    private JTextField newIsdn;  
    private JTextField newName;  
    private JSpinner newPrice;  
    private JButton addButton;  
    private JButton resetButton;  
    private MainFrame table;  
      
  
    public AddBookDialog(MainFrame table){
    	setTitle("添加书籍");  
        this.table = table;  
        this.setModal(true);  
        this.setSize(400,400);  
        this.setResizable(false);  
        this.setLocationRelativeTo(null);  
        getContentPane().setLayout(null);  
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);  
          
        inisComponents();  
    }  
      
  
    private void inisComponents() {            
        newIsdn = new JTextField();  
        newIsdn.setBounds(115, 74, 200, 30);  
        getContentPane().add(newIsdn);  
          
        newName = new JTextField();  
        newName.setBounds(112, 148, 200, 30);  
        getContentPane().add(newName);  
          
        SpinnerModel sModel = new SpinnerNumberModel(1.0, 0.1, 5.0, 0.1);  
        newPrice = new JSpinner(sModel);  
        newPrice.setBounds(115, 216, 200,30);  
        getContentPane().add(newPrice);  
          
        addButton = new JButton("添加");  
        addButton.setBounds(94, 300, 70, 30);  
        addButton.addActionListener(new ActionListener() {  
            @Override  
            public void actionPerformed(ActionEvent e) {  
                Object obj = e.getSource();  
                if(obj == addButton){             
                    String isdn = newIsdn.getText();  
                    String name = newName.getText();  
                    String pricestr = String.format("%.1f", newPrice.getModel().getValue());  
                    double price =Double.parseDouble(pricestr);  
                    table.getBookManager().addBook(new Book(isdn,name,price));  
                    table.refreshTableModel();  
                      
                    AddBookDialog.this.dispose();  
                }  
            }  
        });  
        getContentPane().add(addButton);  
          
        resetButton = new JButton("重置");  
        resetButton.setBounds(230, 300, 70, 30);  
        resetButton.addActionListener(new ActionListener() {  
            @Override  
            public void actionPerformed(ActionEvent e) {  
                Object obj = e.getSource();  
                if(obj == resetButton){  
                    newIsdn.setText("");
                    newName.setText("");
                    newPrice.setValue(1);
                }  
            }  
        });  
        getContentPane().add(resetButton);  
        
        JLabel label = new JLabel("书名");
        label.setBounds(68, 80, 49, 18);
        getContentPane().add(label);
        
        JLabel label_1 = new JLabel("编号");
        label_1.setBounds(68, 154, 30, 18);
        getContentPane().add(label_1);
        
        JLabel label_2 = new JLabel("价格");
        label_2.setBounds(68, 222, 36, 18);
        getContentPane().add(label_2);
          
   
        Font font = new Font("宋体", Font.PLAIN, 14);  
        for (Component c : this.getContentPane().getComponents()) {  
            c.setFont(font);  
        }  
    }  
  
    /*public static void main(String[] args)  throws Exception{  
        UIManager.setInstalledLookAndFeels(UIManager.getInstalledLookAndFeels());  
        new AddBookDialog(null).setVisible(true);  
    } */ 
}  
