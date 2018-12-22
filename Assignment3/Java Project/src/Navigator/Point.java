package Navigator;

public class Point
{
	private int X;
	private int Y;
	
	public Point(int x, int y)
	{
		this.X = x;
		this.Y = y;
	}
	
	public double GetDistance(Point from)
	{
		return Math.sqrt(Math.pow(Math.abs(this.getX() - from.getX()), 2) + Math.pow(Math.abs(this.getY() - from.getY()), 2));
	}
	
	public int getX()
	{
		return X;
	}
	
	public void setX(int x)
	{
		this.X = x;
	}
	
	public int getY()
	{
		return Y;
	}
	
	public void setY(int y)
	{
		this.Y = y;
	}
}
