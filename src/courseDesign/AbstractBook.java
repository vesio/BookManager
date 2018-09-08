package courseDesign;

import java.util.Date;

/**
 * 
 * @author Vesio
 *
 */
public abstract  class AbstractBook implements BookInterface{

	protected String Bname;
	protected String Bnum;
	protected double Bprice;
	protected boolean Bstate;
	protected Date Bday;
	protected int Bcount;
	//BClassProtected 
	protected String BClass;
	public abstract void setTheClass(String str);
	public AbstractBook() {
		BClass="无分类";
		Bcount=0;
	}
	/**
	 * @param name 
	 * @param num
	 * @param price
	 * @param state ״̬
	 * @param day 
	 * @param theClass
	 */
	public AbstractBook(String name,String num,double price,boolean state,Date day,String theClass) {
		Bname=name;
		Bnum=num;
		Bprice=price;
		Bstate=state;
		Bday=day;
		BClass=theClass;
		Bcount=0;
	}
	
	public AbstractBook(String name,String num,double price) {
		Bname=name;
		Bnum=num;
		Bprice=price;
		Bstate=true;
		Bday=new Date();
		BClass="无分类";
		Bcount=0;
	}
	
	public String getTheClass(){
		return BClass;
	}
	
	
	@Override
	public String getName() {
		return Bname;
	}
	@Override
	public Date getDay() {
		return Bday;
	}
	@Override
	public double getPrice() {
		return Bprice;
	}
	@Override
	public String getNum() {
		return Bnum;
	}
	@Override
	public boolean getState() {
		return Bstate;
	}
	@Override
	public int getCount() {
		return Bcount;
	}
	@Override
	public void setName(String name) {
		Bname=name;
		
	}
	@Override
	public void setDay(Date day) {
		Bday=day;
		
	}
	@Override
	public void setPrice(double price) {
		Bprice=price;
		
	}
	@Override
	public void setNum(String num) {
		Bnum=num;
	}
	@Override
	public void setState(boolean state) {
		Bstate=state;
	}
	@Override
	public void setCount(int count) {
		Bcount=count;
	}


}
