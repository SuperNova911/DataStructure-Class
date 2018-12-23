package Navigator;

import java.util.ArrayList;

public class IntersectionPoint extends Point
{
	private ArrayList<Road> DestinationList;
	
	public IntersectionPoint(Point point)
	{
		super(point.getX(), point.getY());
		DestinationList = new ArrayList<>();
	}

	public IntersectionPoint(Point point, Road destination)
	{
		super(point.getX(), point.getY());
		DestinationList = new ArrayList<>();
		DestinationList.add(destination);
	}
	
	public void AddDestination(Road destination)
	{
		DestinationList.add(destination);
	}
	
	public boolean HasDestination(Road destination)
	{
		for (Road road : DestinationList)
		{
			if (road.equals(destination))
			{
				return true;
			}
		}
		
		return false;
	}
	
	public boolean IsConnected(IntersectionPoint otherPoint)
	{
		for (Road otherRoad : otherPoint.DestinationList)
		{
			if (this.HasDestination(otherRoad))
			{
				return true;
			}
		}
		
		return false;
	}
	
	public ArrayList<Road> getDestinationList()
	{
		return DestinationList;
	}
}
