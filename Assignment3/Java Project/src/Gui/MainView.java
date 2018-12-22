package Gui;

import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.Color;
import javax.swing.border.LineBorder;

import Navigator.IMapSize;
import Navigator.IntersectionPoint;
import Navigator.MapFrame;
import Navigator.Point;
import Navigator.Road;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MainView extends JFrame implements IMapSize
{
	private JPanel contentPane;
	private JPanel panel_map;
	private JPanel panel_button;
	
	private JButton btn_generateRandomRoad;
	private JButton btn_findShortestPath;
	private JButton btn_getMST;
	
	private MapFrame mapFrame;
	
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				try
				{
					MainView frame = new MainView();
					frame.setVisible(true);
				} catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}

	public MainView()
	{
		InitializeGUI();
		
		Initialize();	
		DrawLine();
	}
	
	private void InitializeGUI()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0, 0, 780, 560);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		panel_map = new JPanel()
		{
			public void paintComponent(Graphics g)
			{
				super.paintComponent(g);
				
				// 도로 그리기
				int x1, y1, x2, y2;
				for (Road road : mapFrame.RoadList)
				{	
					x1 = road.getPoint1().getX() / (MAX_X / panel_map.getWidth());
					y1 = road.getPoint1().getY() / (MAX_Y / panel_map.getHeight());
					x2 = road.getPoint2().getX() / (MAX_X / panel_map.getWidth());
					y2 = road.getPoint2().getY() / (MAX_Y / panel_map.getHeight());
					g.drawLine(x1, y1, x2, y2);
				}
				
				// 교차점 그리기
				for (IntersectionPoint intersectionPoint : mapFrame.IntersectionPointList)
				{
					g.fillOval(intersectionPoint.getX() / (MAX_X / panel_map.getWidth()) - 3,
							intersectionPoint.getY() / (MAX_Y / panel_map.getHeight()) -3, 7, 7);
				}

				// 시작, 도착 지점 그리기
				if (mapFrame.IsValidStartPoint)
				{
					g.setColor(Color.GREEN);
					g.fillOval(mapFrame.StartPoint.getX() / (MAX_X / panel_map.getWidth()) - 5,
							mapFrame.StartPoint.getY() / (MAX_Y / panel_map.getHeight()) - 5, 10, 10);
				}
				if (mapFrame.IsValidEndPoint)
				{
					g.setColor(Color.BLUE);
					g.fillOval(mapFrame.EndPoint.getX() / (MAX_X / panel_map.getWidth()) - 5, 
							mapFrame.EndPoint.getY() / (MAX_Y / panel_map.getHeight()) - 5, 10, 10);	
				}
				
				// 최단 경로 그리기
				if (mapFrame.IsValidShortestPathList)
				{
					g.setColor(Color.RED);
					for (Point point : mapFrame.ShortestPathList)
					{
						g.fillOval(point.getX() / (MAX_X / panel_map.getWidth()) - 5, 
								point.getY() / (MAX_X / panel_map.getWidth()) - 5, 10, 10);
					}
				}
			}
		};
		panel_map.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mousePressed(MouseEvent arg0) 
			{
				int x, y;
				x = arg0.getX() * (MAX_X / panel_map.getWidth());
				y = arg0.getY() * (MAX_Y / panel_map.getHeight());
				
				if (arg0.getButton() == MouseEvent.BUTTON1)
				{
					mapFrame.StartPoint = new Point(x, y);
					mapFrame.IsValidShortestPathList = false;
					mapFrame.IsValidStartPoint = true;
					System.out.println("x: " + x + ", y: " + y);
				}
				else if (arg0.getButton() == MouseEvent.BUTTON3)
				{
					mapFrame.EndPoint = new Point(x, y);
					mapFrame.IsValidShortestPathList = false;
					mapFrame.IsValidEndPoint = true;
					System.out.println("x: " + x + ", y: " + y);
				}
				else
				{
					System.out.println("Unknown mouse button");
				}
				
				panel_map.repaint();
			}
		});
		panel_map.setBorder(new LineBorder(new Color(0, 0, 0)));
		panel_map.setBackground(Color.WHITE);
		panel_map.setBounds(12, 10, 500, 500);
		contentPane.add(panel_map);
		
		panel_button = new JPanel();
		panel_button.setBounds(524, 10, 229, 500);
		contentPane.add(panel_button);
		panel_button.setLayout(null);
		
		btn_generateRandomRoad = new JButton("Generate Random Road");
		btn_generateRandomRoad.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mouseClicked(MouseEvent arg0) 
			{
				mapFrame.GenerateRandomRoad();
				mapFrame.IsValidShortestPathList = false;
				mapFrame.IsValidStartPoint = false;
				mapFrame.IsValidEndPoint = false;
				panel_map.repaint();
			}
		});
		btn_generateRandomRoad.setBounds(12, 10, 205, 34);
		panel_button.add(btn_generateRandomRoad);
		
		btn_findShortestPath = new JButton("Find Shortest Path");
		btn_findShortestPath.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mouseClicked(MouseEvent e) 
			{
				mapFrame.FindShortestPath();
				panel_map.repaint();
			}
		});
		btn_findShortestPath.setBounds(12, 54, 205, 34);
		panel_button.add(btn_findShortestPath);
		
		btn_getMST = new JButton("Get MST");
		btn_getMST.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mouseClicked(MouseEvent e) 
			{
				
			}
		});
		btn_getMST.setBounds(12, 98, 205, 34);
		panel_button.add(btn_getMST);
	}
	
	private void Initialize()
	{
		mapFrame = new MapFrame();
		
	}
	
	private void DrawLine()
	{

	}
}
