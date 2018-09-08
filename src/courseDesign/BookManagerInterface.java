package courseDesign;

/**
 * 
 * add delete edit search
 * Manage Interface
 * @author Vesio
 * @version 1.0
 *
 */
public interface BookManagerInterface {

	public boolean addBook(Book newBook);
	public boolean delBookByNnum(String num);
	public Book editBookByNum(String num);
	public Book searchBookByNum(String num);
	
}
