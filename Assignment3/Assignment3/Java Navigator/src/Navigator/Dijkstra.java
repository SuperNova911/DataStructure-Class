package Navigator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class Dijkstra
{
	private ArrayList<IntersectionPoint> IntersectionPointList;
	private double[][] IntersectionTable; 
	
	public Dijkstra(ArrayList<IntersectionPoint> intersectionPointList)
	{
		Initialize();
		
		IntersectionPointList = intersectionPointList;
		int intersectionNumber = IntersectionPointList.size();
		IntersectionTable = new double[intersectionNumber][intersectionNumber];
		
		for (double[] row: IntersectionTable)
		    Arrays.fill(row, Double.MAX_VALUE);
		
		IntersectionPoint intersection;
		for (int i = 0; i < intersectionNumber; i++)
		{
			intersection = IntersectionPointList.get(i);
			
			for (int j = 0; j < intersectionNumber; j++)
			{
				if (i == j)
				{
					IntersectionTable[i][j] = IntersectionTable[j][i] = 0;
					continue;
				}
				
				if (intersection.IsConnected(IntersectionPointList.get(j)))
				{
					IntersectionTable[i][j] = IntersectionTable[j][i] = intersection.GetDistance(IntersectionPointList.get(j));
				}
			}
		}
	}
	
	private void Initialize()
	{
		IntersectionPointList = new ArrayList<>();
	}
	
	public ArrayList<Point> FindShortestPath(Point startPoint, Point endPoint)
	{
		boolean[] hasVisited = new boolean[IntersectionPointList.size()];
		double[] distance = new double[IntersectionPointList.size()];
		int[] path = new int[IntersectionPointList.size()];
		
		Arrays.fill(hasVisited, false);
		Arrays.fill(distance, Double.MAX_VALUE);
		Arrays.fill(path, -1);
		
		int startIntersectionIndex, endIntersectionIndex;
		startIntersectionIndex = endIntersectionIndex = -1;
				
		for (int index = 0; index < IntersectionPointList.size(); index++)
		{	
			if (IntersectionPointList.get(index).IsEqualPoint(startPoint))
			{
				startIntersectionIndex = index;
			}
			
			if (IntersectionPointList.get(index).IsEqualPoint(endPoint))
			{
				endIntersectionIndex = index;
			}
			
			if (startIntersectionIndex != -1 && endIntersectionIndex != -1)
			{
				break;
			}
		}
		
		distance[startIntersectionIndex] = 0;
		
		double bestDistance;
		int bestWay = 0;
		for (int i = 0; i < IntersectionPointList.size(); i++)
		{
			bestDistance = Double.MAX_VALUE;
			for (int j = 0; j < IntersectionPointList.size(); j++)
			{
				if (hasVisited[j] == false && distance[j] < bestDistance)
				{
					bestWay = j;
					bestDistance = distance[j];
				}
			}
			
			hasVisited[bestWay] = true;
			
			if (distance[bestWay] == Double.MAX_VALUE)
			{
				break;
			}
			else
			{
				for (int j = 0; j < IntersectionPointList.size(); j++)
				{
					if (distance[j] > distance[bestWay] + IntersectionTable[bestWay][j])
					{
						distance[j] = distance[bestWay] + IntersectionTable[bestWay][j];
						path[j] = bestWay;
					}
				}
			}
		}
		
		ArrayList<Point> shortestPathList = new ArrayList<>();
		Stack<Integer> stack = new Stack<>();
		int pointer = endIntersectionIndex;
		
		while (true)
		{
			if (path[pointer] != -1 && startIntersectionIndex != endIntersectionIndex)
			{
				stack.push(pointer);
				pointer = path[pointer];
			}
			else
			{
				stack.push(startIntersectionIndex);
				break;
			}
		}
		
		while (stack.isEmpty() == false)
		{
			shortestPathList.add(IntersectionPointList.get(stack.pop()));
		}
		
		return shortestPathList;
	}
}
