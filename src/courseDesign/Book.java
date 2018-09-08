package courseDesign;

import java.text.SimpleDateFormat;

public class Book extends AbstractBook{

	@Override
	public void setTheClass(String str) {
		// TODO Auto-generated method stub
		BClass=str;
	}
	public Book() {
		// TODO Auto-generated constructor stub
		BClass="无分类";
	}
	public Book(String name,String num,double price) {
		super(name, num, price);
	}
	public boolean setCount() {
		int t=getCount();
		setCount(t+1);
		return true;
	}
	
	@Override  
    public String toString() {
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy年MM月dd日");
        return  Bnum + "#" + Bname 
                + "#" + Bprice + "#" + Bstate + "#"  
                + sdf.format(Bday) + "#" + Bcount +"\r\n";  
    }
	

}
