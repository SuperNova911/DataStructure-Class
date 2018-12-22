package Navigator;

import java.util.ArrayList;

public class Dijkstra
{
	private ArrayList<IntersectionPoint> IntersectionPointList;
	private double[][] IntersectionTable; 
	
	public Dijkstra(ArrayList<IntersectionPoint> intersectionPointList)
	{
		Initialize();
		
		int intersectionNumber = intersectionPointList.size();
		IntersectionPointList = intersectionPointList;
		IntersectionTable = new double[intersectionNumber][intersectionNumber];
		for (int i = 0; i < intersectionNumber; i++)
		{
			for (int j = 0; j < intersectionNumber; j++)
			{
				if (intersectionPointList.get(i).)
			}
		}
	}
	
	private void Initialize()
	{
		IntersectionPointList = new ArrayList<>();
	}
	
	public void FindShortestPath(Point startPoint, Point endPoint)
	{
		boolean[] hasVisited = new boolean[IntersectionPointList.size()];
		double[] distance = new double[IntersectionPointList.size()];
		
		for (double dis : distance)
		{
			dis = Double.MAX_VALUE;
		}
		
		IntersectionPoint startIntersectionPoint, endIntersectionPoint;
		startIntersectionPoint = endIntersectionPoint = null;
		
		for (IntersectionPoint intersectionPoint : IntersectionPointList)
		{
			if (intersectionPoint.getX() == startPoint.getX() && intersectionPoint.getY() == startPoint.getY())
			{
				startIntersectionPoint = intersectionPoint;
			}
			
			if (intersectionPoint.getX() == endPoint.getX() && intersectionPoint.getY() == endPoint.getY())
			{
				endIntersectionPoint = intersectionPoint;
			}
			
			if (startIntersectionPoint != null && endIntersectionPoint != null)
			{
				break;
			}
		}
		
		if (startIntersectionPoint == null || endIntersectionPoint == null)
		{
			System.out.println("시작, 도착 지점을 찾지 못함");
			return;
		}
		
		int startIntersectionIndex = 0;
		for (int index = 0; index < IntersectionPointList.size(); index++)
		{
			if (IntersectionPointList.get(index).getX() == startPoint.getX() && IntersectionPointList.get(index).getY() == startPoint.getY())
			{
				startIntersectionIndex = index;
				break;
			}
		}
		
		distance[startIntersectionIndex] = 0;
		hasVisited[startIntersectionIndex] = true;
		
		for (int index = 0; index < IntersectionPointList.size(); index++)
		{
			if (hasVisited[index] == false && IntersectionPointList.get(index).has)
		}
	}
}
