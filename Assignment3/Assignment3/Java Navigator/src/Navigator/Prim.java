package Navigator;

import java.util.ArrayList;
import java.util.Arrays;

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
		ArrayList<PrimLink> linkList = new ArrayList<>();
		ArrayList<Road> roadList = new ArrayList<>();
		
		Arrays.fill(hasVisited, false);
				
		int currentIndex = 0;
		double bestDistance;
		PrimLink bestLink = null;
		
		
		for (int startIndex = 0; startIndex < IntersectionPointList.size(); startIndex++)
		{
			if (hasVisited[startIndex])
			{
				continue;
			}
			
			hasVisited[startIndex] = true;
			currentIndex = startIndex;
			
			while (currentIndex != -1)
			{
				for (int index = 0; index < IntersectionPointList.size(); index++)
				{
					if (hasVisited[index] == false && IntersectionTable[currentIndex][index] != Double.MAX_VALUE && currentIndex != index)
					{
						AddPrimLinkToList(linkList, new PrimLink(currentIndex, index, IntersectionTable[currentIndex][index]));
					}
				}
				
				bestDistance = Double.MAX_VALUE;
				bestLink = null;
				currentIndex = -1;
				
				for (int i = 0; i < hasVisited.length; i++)
				{
					if (hasVisited[i] == false)
					{
						continue;
					}
					
					for (int j = 0; j < linkList.size(); j++)
					{
						if (hasVisited[linkList.get(j).getDestination(i)] == false && 
						linkList.get(j).getDistance() < bestDistance)
						{
							bestLink = linkList.get(j);
							bestDistance = bestLink.getDistance();
							currentIndex = bestLink.getDestination(i);
						}
					}
				}
				
				if (bestLink != null)
				{
					hasVisited[currentIndex] = true;
					roadList.add(new Road(IntersectionPointList.get(bestLink.NodeA), IntersectionPointList.get(bestLink.NodeB)));
					linkList.remove(bestLink);
				}
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
