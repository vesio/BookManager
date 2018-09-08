package courseDesign;

import java.util.Date;

public class LiteraryBook extends AbstractBook {
	@Override
	public void setTheClass(String string) {
		// TODO Auto-generated method stub
		super.BClass=string;
	}
	public LiteraryBook() {
		// TODO Auto-generated constructor stub
		BClass="文学类";
	}
	public LiteraryBook(String name,String num,double price,boolean  state,Date day,String theClass) {
		super(name, num, price, state, day, theClass);
	}
}
