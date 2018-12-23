package Navigator;

import java.util.ArrayList;

public class MapFrame implements IMapSize
{	
	public ArrayList<Road> RoadList;
	public ArrayList<IntersectionPoint>IntersectionPointList;
	public ArrayList<Point> ShortestPathList;
	public ArrayList<Road> MSTList;
	
	public boolean IsValidStartPoint;
	public boolean IsValidEndPoint;
	public boolean ShowShortestPath;
	public boolean ShowMST;
	
	public Point StartPoint;
	public Point EndPoint;
	
	private int RandomRoadNumber;
	
	public MapFrame()
	{
		Initialize();
		GenerateRandomRoad();
	}
	
	private void Initialize()
	{
		RoadList = new ArrayList<>();
		IntersectionPointList = new ArrayList<>();
		ShortestPathList = new ArrayList<>();
		MSTList = new ArrayList<>();
		
		IsValidStartPoint = false;
		IsValidEndPoint = false;
		ShowShortestPath = false;
		ShowMST = false;
		
		StartPoint = new Point(0, 0);
		EndPoint = new Point(0, 0);
		
		RandomRoadNumber = 6;
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
					IntersectionPoint newIntersectionPoint = new IntersectionPoint(intersection, newRoad);
					newIntersectionPoint.AddDestination(road);
					IntersectionPointList.add(newIntersectionPoint);
				}
			}
		}
		
		RoadList.add(newRoad);
	}

	public void GenerateRandomRoad()
	{
		RoadList.clear();
		IntersectionPointList.clear();
		
		for (int index = 0; index < RandomRoadNumber; index++)
		{
			Road newRoad = new Road();
			newRoad.GenerateRandomRoad();
			AddRoadToList(newRoad);
		}
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
		
		if (bestStartPoint == bestEndPoint)
		{
			return;
		}

		Dijkstra dijkstra = new Dijkstra(IntersectionPointList);

		ShortestPathList.add(StartPoint);
		ShortestPathList.addAll(dijkstra.FindShortestPath(bestStartPoint, bestEndPoint));
		ShortestPathList.add(EndPoint);
		ShowShortestPath = true;
	}
	
	public void GetMST()
	{
		Prim prim = new Prim(IntersectionPointList);
		MSTList = prim.GetMST();
		ShowMST = true;
	}
}
