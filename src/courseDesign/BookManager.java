package courseDesign;

import java.util.LinkedList;
import javax.swing.JOptionPane;

public class BookManager implements BookManagerInterface{

	LinkedList<Book> myBooks=new LinkedList<>();
	
	public BookManager() {
		myBooks.add(new Book("三国演义","90001",50.00));
		myBooks.add(new Book("Java","90002",20.00));
		myBooks.add(new Book("Python","90003",30.00));
		myBooks.add(new Book("C++","90004",10.00));
		
	}
	
	public LinkedList<Book> getAll(){
		return myBooks;
	}
	
	@Override
	public boolean addBook(Book newBook) {
		if(searchBookByNum(newBook.getNum())==null) {
			myBooks.add(newBook);
			return true;
		}	
		else
			return false;
			
	}

	@Override
	public boolean delBookByNnum(String num) {
		if(searchBookByNum(num)==null)
			return false;
		else
			myBooks.remove(searchBookByNum(num));
		return true;
	}

	@Override
	public Book editBookByNum(String num) {	
		return searchBookByNum(num);
		
	}

	@Override
	public Book searchBookByNum(String num) {
		for(Book b:myBooks) {
			if(b.getNum().equals(num))
				return b;
		}
		return null;
	}
	
	public Book searchBookByName(String name) {
		for(Book b:myBooks) {
			if(b.getName().contains(name))
				return b;
		}
		return null;
	}

}
