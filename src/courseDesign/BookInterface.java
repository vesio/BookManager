package courseDesign;

import java.util.Date;

/**
 * 
 * The basic properties
 * Book Interface
 * @author Vesio
 *
 */
public interface BookInterface {
	public String getName();
	public Date getDay();
	public double getPrice();
	public String getNum();
	public boolean getState();
	public int getCount();
	
	public void setName(String name);
	public void setDay(Date day);
	public void setPrice(double price);
	public void setNum(String num);
	public void setState(boolean state);
	public void setCount(int count);

}
