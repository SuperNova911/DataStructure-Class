package Navigator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class Road implements IMapSize
{
	private Point Point1;
	private Point Point2;
	
	public Road()
	{
		Initialize();	
	}
	
	private void Initialize()
	{
		Point1 = new Point(0, 0);
		Point2 = new Point(0, 0);
	}
	
	public void GenerateRandomRoad()
	{
		Random random = new Random();
		
		ArrayList<Point> pointList = new ArrayList<Point>(Arrays
				.asList(new Point(0, random.nextInt(MAX_Y)), 
						new Point(MAX_X - 1, random.nextInt(MAX_Y)), 
						new Point(random.nextInt(MAX_X), 0), 
						new Point(random.nextInt(MAX_X), MAX_Y - 1)));

		Point targetPoint = pointList.get(random.nextInt(pointList.size()));
		pointList.remove(targetPoint);
		this.Point1 = targetPoint;
		
		targetPoint = pointList.get(random.nextInt(pointList.size()));
		this.Point2 = targetPoint;
	}
	
	public Point FindIntersection(Road anotherRoad)
	{
		int x, y;
		Point p1, p2, p3, p4;
		
		p1 = this.getPoint1();
		p2 = this.getPoint2();
		p3 = anotherRoad.getPoint1();
		p4 = anotherRoad.getPoint2();
		
		double slope1, slope2;
		slope1 = (double) (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
		slope2 = (double) (p4.getY() - p3.getY()) / (p4.getX() - p3.getX());
		if (slope1 == slope2)
		{
			return null;
		}

		x = ((p1.getX() * p2.getY() - p1.getY() * p2.getX()) * (p3.getX() - p4.getX()) - (p1.getX() - p2.getX()) * (p3.getX() * p4.getY() - p3.getY() * p4.getX())) / ((p1.getX() - p2.getX()) * (p3.getY() - p4.getY()) - (p1.getY() - p2.getY()) * (p3.getX() - p4.getX()));
		y = ((p1.getX() * p2.getY() - p1.getY() * p2.getX()) * (p3.getY() - p4.getY()) - (p1.getY() - p2.getY()) * (p3.getX() * p4.getY() - p3.getY() * p4.getX())) / ((p1.getX() - p2.getX()) * (p3.getY() - p4.getY()) - (p1.getY() - p2.getY()) * (p3.getX() - p4.getX()));
		
		return new Point(x, y);
	}
	
	public Point getPoint1()
	{
		return Point1;
	}

	public Point getPoint2()
	{
		return Point2;
	}
}
