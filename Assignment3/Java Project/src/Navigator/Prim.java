package Navigator;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;

public class Prim
{
	private ArrayList<IntersectionPoint> IntersectionPointList;
	private double[][] IntersectionTable; 
	
	public Prim(ArrayList<IntersectionPoint> intersectionPointList)
	{
		IntersectionPointList = new ArrayList<>();
		
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
	
	private void AddPrimLinkToList(ArrayList<PrimLink> linkList, PrimLink newLink)
	{
		for (PrimLink link : linkList)
		{
			if (link.IsSameLink(newLink))
			{
				return;
			}
		}
		
		linkList.add(newLink);
	}
	
	public ArrayList<Road> GetMST()
	{
		boolean[] hasVisited = new boolean[IntersectionPointList.size()];
		Deque<Integer> queue = new ArrayDeque<>();
		ArrayList<Road> roadList = new ArrayList<>();
		ArrayList<PrimLink> linkList = new ArrayList<>();
		
		Arrays.fill(hasVisited, false);
		
		final int startIndex = 0;
		queue.add(startIndex);
		
		
		int currentIntersection = 0;
		
		double bestDistance;
		int bestWay = -1;
		
		hasVisited[startIndex] = true;
		while (currentIntersection != -1)
		{
			for (int index = 0; index < IntersectionPointList.size(); index++)
			{
				if (IntersectionTable[currentIntersection][index] != Double.MAX_VALUE)
				{
					AddPrimLinkToList(linkList, new PrimLink(currentIntersection, index, IntersectionTable[currentIntersection][index]));
				}
			}
			
			bestDistance = Double.MAX_VALUE;
			for (int index = 0; index < linkList.size(); index++)
			{
				if (hasVisited[linkList.get(currentIntersection).getDestination(currentIntersection)] == false && 
					linkList.get(index).getDistance() < bestDistance)
				{
					bestDistance = linkList.get(index).getDistance();
					bestWay = linkList.get(index).getDestination(currentIntersection);
				}
			}
		}
		
		while (queue.isEmpty() == false)
		{
			currentIntersection = queue.poll();
			
			bestDistance = Double.MAX_VALUE;
			for (int i = 0; i < IntersectionPointList.size(); i++)
			{
				if (hasVisited[i] == false && IntersectionTable[currentIntersection][i] < bestDistance)
				{
					bestDistance = IntersectionTable[currentIntersection][i]; 
					bestWay = i;
				}
			}
			
			if (bestWay != -1)
			{
				hasVisited[bestWay] = true;
				queue.add(bestWay);	
				
				roadList.add(new Road(IntersectionPointList.get(currentIntersection), IntersectionPointList.get(bestWay)));
			}
		}
		
		return roadList;
	}
	
	private class PrimLink
	{
		private int NodeA;
		private int NodeB;
		private double Distance;
		
		public PrimLink(int nodeA, int nodeB, double distance)
		{
			this.NodeA = nodeA;
			this.NodeB = nodeB;
			this.Distance = distance;
		}
		
		public boolean IsSameLink(PrimLink otherLink)
		{
			return (this.NodeA == otherLink.NodeA && this.NodeB == otherLink.NodeB) || (this.NodeA == otherLink.NodeB&& this.NodeB == otherLink.NodeA);
		}
		
		public int getDestination(int from)
		{
			return (from == this.NodeA) ? NodeB : NodeA;
		}
		
		public double getDistance()
		{
			return Distance;
		}
	}
}
