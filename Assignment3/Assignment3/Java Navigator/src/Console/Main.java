package Console;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

import Navigator.IMapSize;
import Navigator.IntersectionPoint;
import Navigator.MapFrame;
import Navigator.Point;
import Navigator.Road;

public class Main implements IMapSize
{
	public static MapFrame mapFrame;
	
	public static double[][] IntersectionTable; 
	public static ArrayList<IntersectionPoint> IntersectionList;
	
	public static void main(String[] args) 
	{
		Initialize();
		System.out.println("맵 크기: " + MAX_X + " x " + MAX_Y);
		
		GenerateRandomRoad(10);
		
		Scanner scanner = new Scanner(System.in);
		int userInput;
		
		while (true)
		{
			System.out.println("1. 랜덤 도로 생성, 2. 각 교차점 정보 출력, 3. 랜덤 입력 기반 최단 경로 탐색, 4. MST 구하기");
			System.out.print("입력: ");
			
			try
			{
				userInput = Integer.parseInt(scanner.nextLine());
				
				switch (userInput)
				{
				case 1:
					System.out.print("생성할 랜덤 도로 개수(N): ");
					userInput = Integer.parseInt(scanner.nextLine());
					GenerateRandomRoad(userInput);
					break;
				case 2:
					ShowIntersectionInfo();
					break;
				case 3:
					System.out.print("랜덤 탐색 횟수: ");
					userInput = Integer.parseInt(scanner.nextLine());
					FindShortestPath(userInput);
					break;
				case 4:
					GetMST();
					break;
				}
			}
			catch (NumberFormatException e)
			{
				System.out.println(e.getMessage());
			}
		}
	}

	private static void Initialize()
	{
		mapFrame = new MapFrame();	
	}
	
	private static void GenerateRandomRoad(int n)
	{
		mapFrame.RandomRoadNumber = n;
		mapFrame.GenerateRandomRoad();
		
		System.out.println("랜덤 도로 개수(N): " + mapFrame.RandomRoadNumber);
		
		IntersectionList = mapFrame.IntersectionPointList;
		int intersectionNumber = IntersectionList.size();
		
		IntersectionTable = new double[intersectionNumber][intersectionNumber];
		for (double[] row: IntersectionTable)
		    Arrays.fill(row, Double.MAX_VALUE);

		IntersectionPoint intersection;
		for (int i = 0; i < intersectionNumber; i++)
		{
			intersection = IntersectionList.get(i);
			
			for (int j = 0; j < intersectionNumber; j++)
			{
				if (i == j)
				{
					IntersectionTable[i][j] = IntersectionTable[j][i] = 0;
					continue;
				}
				
				if (intersection.IsConnected(IntersectionList.get(j)))
				{
					IntersectionTable[i][j] = IntersectionTable[j][i] = intersection.GetDistance(IntersectionList.get(j));
				}
			}
		}
		
		int edgeNumber = 0;
		for (int i = 0; i < intersectionNumber; i++)
		{
			for (int j = i; j < intersectionNumber; j++)
			{
				if (IntersectionTable[i][j] != 0 && IntersectionTable[i][j] != Double.MAX_VALUE)
				{
					edgeNumber++;
				}
			}
		}
		
		
		System.out.println("교차점 개수: " + intersectionNumber + ", 간선 개수: " + edgeNumber);
	}
	
	private static void ShowIntersectionInfo()
	{
		final int intersectionNumber = IntersectionList.size();
		
		for (int i = 0; i < intersectionNumber; i++)
		{
			for (int j = 0; j < intersectionNumber; j++)
			{
				if (IntersectionTable[i][j] != 0 && IntersectionTable[i][j] != Double.MAX_VALUE)
				{
					System.out.println("교차점 좌표: (" + IntersectionList.get(i).getX() + ", " + IntersectionList.get(i).getY() + "), 인덱스: " + i + ", 연결된 교차점 인덱스: " + j + ", 거리: " + IntersectionTable[i][j]);
				}
			}
		}
	}
	
	private static void FindShortestPath(int n)
	{
		Random random = new Random();
		ArrayList<Integer> pathList = new ArrayList<>();
		
		mapFrame.IsValidStartPoint = mapFrame.IsValidEndPoint = true;
		for (int index = 0; index < n; index++)
		{
			mapFrame.StartPoint.setX(random.nextInt(MAX_X));
			mapFrame.StartPoint.setY(random.nextInt(MAX_Y));
			mapFrame.EndPoint.setX(random.nextInt(MAX_X));
			mapFrame.EndPoint.setY(random.nextInt(MAX_Y));
			System.out.print("from (" + mapFrame.StartPoint.getX() + ", " + mapFrame.StartPoint.getY() + ") to (" + mapFrame.EndPoint.getX() + ", " + mapFrame.EndPoint.getY() + "), ");
			
			mapFrame.FindShortestPath();
			
			System.out.print("최단 경로: ");
			
			if (mapFrame.ShortestPathList.size() == 0)
			{
				System.out.println("시작 교차점과 도착 교차점이 같음");
				continue;
			}
			
			pathList.clear();
			for (Point point : mapFrame.ShortestPathList)
			{
				for (int intersectionIndex = 0; intersectionIndex < IntersectionList.size(); intersectionIndex++)
				{
					if (point.IsEqualPoint(IntersectionList.get(intersectionIndex)))
					{
						pathList.add(intersectionIndex);
					}
				}
			}
			
			for (Integer intersectionIndex : pathList)
			{
				System.out.print(intersectionIndex + " ");	
			}
			System.out.println();
		}
	}
	
	private static void GetMST()
	{
		System.out.println("MST계산중...");
		mapFrame.GetMST();
		
		for (Road road : mapFrame.MSTList)
		{
			System.out.print("(");
			for (int index = 0; index < IntersectionList.size(); index++)
			{
				if (IntersectionList.get(index).IsEqualPoint(road.getPoint1()))
				{
					System.out.print(index);
					break;
				}
			}
			System.out.print(", ");
			for (int index = 0; index < IntersectionList.size(); index++)
			{
				if (IntersectionList.get(index).IsEqualPoint(road.getPoint2()))
				{
					System.out.print(index);
					break;
				}
			}
			System.out.print("), 가중치: " + road.getPoint1().GetDistance(road.getPoint2()) + "\n");
		}
	}
}
