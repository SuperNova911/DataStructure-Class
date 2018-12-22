package Navigator;

import java.util.ArrayList;

public class MapFrame implements IMapSize
{	
	public ArrayList<Road> RoadList;
//	public ArrayList<Point> IntersectionList;
	public ArrayList<IntersectionPoint>IntersectionPointList;
	public ArrayList<Point> ShortestPathList;
	
	public boolean IsValidStartPoint;
	public boolean IsValidEndPoint;
	public boolean IsValidShortestPathList;
	
	public Point StartPoint;
	public Point EndPoint;
	
	public MapFrame()
	{
		Initialize();
		
		int defaultRoadNumber = 6;
		for (int index = 0; index < defaultRoadNumber; index++)
		{
			GenerateRandomRoad();
		}
	}
	
	private void Initialize()
	{
		RoadList = new ArrayList<>();
		IntersectionPointList = new ArrayList<>();
		ShortestPathList = new ArrayList<>();
//		IntersectionList = new ArrayList<>();
		
		IsValidStartPoint = false;
		IsValidEndPoint = false;
		IsValidShortestPathList = false;
		
		StartPoint = new Point(0, 0);
		EndPoint = new Point(0, 0);
	}
	
	private void AddRoadToList(Road newRoad)
	{
		Point intersection;
		boolean isIntersectionExist = false;
		
		for (Road road : RoadList)
		{
			intersection = newRoad.FindIntersection(road);
			
			if (intersection == null)
			{
				continue;
			}
			
			if (0 <= intersection.getX() && intersection.getX() < MAX_X && 0 <= intersection.getY() && intersection.getY() < MAX_Y)
			{
				for (IntersectionPoint intersectionPoint : IntersectionPointList)
				{
					if (intersectionPoint.getX() == intersection.getX() && intersectionPoint.getY() == intersection.getY())
					{
						intersectionPoint.AddDestination(road);
						isIntersectionExist = true;
						break;
					}
				}
				
				if (isIntersectionExist == false)
				{
					IntersectionPointList.add(new IntersectionPoint(intersection, road));
				}
			}
		}
		
		RoadList.add(newRoad);
	}

	public void GenerateRandomRoad()
	{
		Road newRoad = new Road();
		newRoad.GenerateRandomRoad();
		AddRoadToList(newRoad);
	}
	
	public void FindShortestPath()
	{
		ShortestPathList.clear();
		
		if (IsValidStartPoint == false || IsValidEndPoint == false)
		{
			return;
		}
		
		double distance;
		double startMinDistance, endMinDistance;
		startMinDistance = endMinDistance = Double.MAX_VALUE;
		Point bestStartPoint, bestEndPoint;
		bestStartPoint = StartPoint;
		bestEndPoint = EndPoint;
		
		for (Point point : IntersectionPointList)
		{
			distance = point.GetDistance(StartPoint);
			if (startMinDistance > distance)
			{
				startMinDistance = distance;
				bestStartPoint = point;
			}

			distance = point.GetDistance(EndPoint);
			if (endMinDistance > distance)
			{
				endMinDistance = distance;
				bestEndPoint = point;
			}
		}

		ShortestPathList.add(bestStartPoint);
		ShortestPathList.add(bestEndPoint);
		
		IsValidShortestPathList = true;
		
		if (bestStartPoint == bestEndPoint)
		{
			return;
		}

		
	}
}
