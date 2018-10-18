public class DoublylinkedList
{
	private int count;
	private Node head;

	public DoublylinkedList()
	{
		count = 0;
		head = new Node();
	}

	public DoublylinkedList(DoublylinkedList linkedList)
	{
		this();
		
		for (int index = 0; index < linkedList.count; index++)
		{
			this.Insert(index, linkedList.Retrieve(index));
		}
	}
	
	public void Insert(int position, int item)
	{
		if (position < 0 || count < position)
			return;
		
		if (position == 0)
		{
			Node newNode = new Node();
			newNode.Data = item;
			newNode.Next = head.Next;
			
			if (head.Next != null)
				head.Next.Prev = newNode;

			head.Next = newNode;
		}
		else
		{
			Node targetNode = head.Next;
			for (int index = 0; index < position - 1; index++)
			{
				targetNode = targetNode.Next;
			}
			
			Node newNode = new Node();
			newNode.Data = item;
			newNode.Prev = targetNode;
			newNode.Next = targetNode.Next;
			
			if (targetNode.Next != null)
				targetNode.Next.Prev = newNode;
			
			targetNode.Next = newNode;
		}
		
		count++;
	}
	
	public void Delete(int position)
	{
		if (position < 0 || count <= position)
			return;
		
		Node targetNode = head.Next;
		if (position == 0)
		{
			head.Next = targetNode.Next;
			
			if (head.Next != null)
				head.Next.Prev = null;
		}
		else
		{
			Node prevNode = targetNode;
			for (int index = 1; index <= position; index++)
			{
				prevNode = targetNode;
				targetNode = targetNode.Next;
			}
			
			prevNode.Next = targetNode.Next;
			
			if (targetNode.Next != null)
				targetNode.Next.Prev = prevNode;
		}
		
		targetNode = null;
		count--;
	}
	
	public int Retrieve(int position)
	{
		if (position < 0 || count - 1 < position)
			return -1;
		
		Node targetNode = head.Next;
		for (int index = 0; index < position; index++)
		{
			targetNode = targetNode.Next;
		}
		
		return targetNode.Data;
	}
	
	public boolean IsEmpty()
	{
		if (count < 1)
			return true;
		else
			return false;
	}
	
	public int Length()
	{
		return count;
	}

	private class Node
	{
		public int Data;
		public Node Prev;
		public Node Next;
		
		public Node()
		{
			Data = 0;
			Prev = null;
			Next = null;
		}
	}
}
