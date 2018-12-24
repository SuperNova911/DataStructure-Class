package Gui;

import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;

import java.awt.BasicStroke;
import java.awt.Color;
import javax.swing.border.LineBorder;

import Navigator.IMapSize;
import Navigator.IntersectionPoint;
import Navigator.MapFrame;
import Navigator.Point;
import Navigator.Road;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.Font;
import javax.swing.JCheckBox;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import javax.swing.JLabel;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;

public class MainView extends JFrame implements IMapSize
{
	private JPanel contentPane;
	private JPanel panel_map;
	private JPanel panel_button;

	private JButton btn_generateRandomRoad;
	private JButton btn_findShortestPath;
	private JButton btn_getMST;
	
	private JCheckBox checkBoxShowIntersectionPoint;
	private JCheckBox checkBoxShowRoad; 

	private JLabel label_ShortestPathLength;
	private JLabel label_ShortestPathLengthValue;
	private JLabel label_MSTCost;
	private JLabel label_MSTCostValue;
	
	private MapFrame mapFrame;
	private JLabel label_MapSize;
	private JLabel lblRoadNumber;

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
				Graphics2D g2 = (Graphics2D)g;

				// 도로 그리기
				int x1, y1, x2, y2;
				if (checkBoxShowRoad.isSelected())
				{
					for (Road road : mapFrame.RoadList)
					{	
						x1 = road.getPoint1().getX() / (MAX_X / panel_map.getWidth());
						y1 = road.getPoint1().getY() / (MAX_Y / panel_map.getHeight());
						x2 = road.getPoint2().getX() / (MAX_X / panel_map.getWidth());
						y2 = road.getPoint2().getY() / (MAX_Y / panel_map.getHeight());
						g.drawLine(x1, y1, x2, y2);
					}
				}

				// 최단 경로 그리기
				if (mapFrame.ShowShortestPath)
				{
					g2.setStroke(new BasicStroke(3));
					g2.setColor(Color.RED);
					for (int index = 0; index < mapFrame.ShortestPathList.size() - 1; index++)
					{
						g2.drawLine(mapFrame.ShortestPathList.get(index).getX() / (MAX_X / panel_map.getWidth()), 
								mapFrame.ShortestPathList.get(index).getY() / (MAX_X / panel_map.getWidth()), 
								mapFrame.ShortestPathList.get(index + 1).getX() / (MAX_X / panel_map.getWidth()), 
								mapFrame.ShortestPathList.get(index + 1).getY() / (MAX_X / panel_map.getWidth()));
					}
					
					label_ShortestPathLengthValue.setText(Double.toString(mapFrame.ShortestDistance));
				}

				if (mapFrame.ShowMST)
				{
					g2.setStroke(new BasicStroke(3));
					g2.setColor(Color.BLUE);
					for (Road road : mapFrame.MSTList)
					{
						x1 = road.getPoint1().getX() / (MAX_X / panel_map.getWidth());
						y1 = road.getPoint1().getY() / (MAX_Y / panel_map.getHeight());
						x2 = road.getPoint2().getX() / (MAX_X / panel_map.getWidth());
						y2 = road.getPoint2().getY() / (MAX_Y / panel_map.getHeight());
						g2.drawLine(x1, y1, x2, y2);
					}
					
					label_MSTCostValue.setText(Double.toString(mapFrame.MSTCost));
				}

				// 교차점 그리기
				if (checkBoxShowIntersectionPoint.isSelected())
				{
					for (IntersectionPoint intersectionPoint : mapFrame.IntersectionPointList)
					{
						g.setColor(Color.BLACK);
						g.fillOval(intersectionPoint.getX() / (MAX_X / panel_map.getWidth()) - 3,
								intersectionPoint.getY() / (MAX_Y / panel_map.getHeight()) -3, 6, 6);
					}
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
					mapFrame.IsValidStartPoint = true;
					mapFrame.ShowShortestPath = false;
				}
				else if (arg0.getButton() == MouseEvent.BUTTON3)
				{
					mapFrame.EndPoint = new Point(x, y);
					mapFrame.IsValidEndPoint = true;
					mapFrame.ShowShortestPath = false;
				}
				else
				{
					System.out.println("Unknown mouse button");
				}

				panel_map.repaint();
			}
		});
		panel_map.setBorder(new LineBorder(new Color(0, 0, 0), 2));
		panel_map.setBackground(Color.WHITE);
		panel_map.setBounds(12, 10, 500, 500);
		contentPane.add(panel_map);

		panel_button = new JPanel();
		panel_button.setBounds(524, 10, 229, 500);
		contentPane.add(panel_button);
		panel_button.setLayout(null);

		btn_generateRandomRoad = new JButton("Generate Random Road");
		btn_generateRandomRoad.setFont(new Font("Consolas", Font.BOLD, 15));
		btn_generateRandomRoad.setBackground(Color.BLUE);
		btn_generateRandomRoad.setForeground(Color.WHITE);
		btn_generateRandomRoad.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mousePressed(MouseEvent arg0) 
			{
				mapFrame.GenerateRandomRoad();
				
				mapFrame.IsValidStartPoint = false;
				mapFrame.IsValidEndPoint = false;
				mapFrame.ShowShortestPath = false;
				mapFrame.ShowMST = false;
				label_ShortestPathLengthValue.setText(Double.toString(mapFrame.ShortestDistance));
				label_MSTCostValue.setText(Double.toString(mapFrame.MSTCost));
				panel_map.repaint();
			}
		});
		btn_generateRandomRoad.setBounds(12, 10, 205, 50);
		btn_generateRandomRoad.setFocusPainted(false);
		panel_button.add(btn_generateRandomRoad);

		btn_findShortestPath = new JButton("Find Shortest Path");
		btn_findShortestPath.setForeground(Color.WHITE);
		btn_findShortestPath.setBackground(Color.BLUE);
		btn_findShortestPath.setFont(new Font("Consolas", Font.BOLD, 15));
		btn_findShortestPath.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mousePressed(MouseEvent e) 
			{
				mapFrame.ShowMST = false;
				mapFrame.FindShortestPath();
				panel_map.repaint();
			}
		});
		btn_findShortestPath.setBounds(12, 70, 205, 50);
		btn_findShortestPath.setFocusPainted(false);
		panel_button.add(btn_findShortestPath);

		btn_getMST = new JButton("Get MST");
		btn_getMST.setFont(new Font("Consolas", Font.BOLD, 15));
		btn_getMST.setBackground(Color.BLUE);
		btn_getMST.setForeground(Color.WHITE);
		btn_getMST.addMouseListener(new MouseAdapter() 
		{
			@Override
			public void mousePressed(MouseEvent e) 
			{
				mapFrame.IsValidStartPoint = false;
				mapFrame.IsValidEndPoint = false;
				mapFrame.ShowShortestPath = false;
				mapFrame.GetMST();
				panel_map.repaint();
			}
		});
		btn_getMST.setBounds(12, 130, 205, 50);
		btn_getMST.setFocusPainted(false);
		panel_button.add(btn_getMST);
		
		checkBoxShowIntersectionPoint = new JCheckBox("Show Intersection Point");
		checkBoxShowIntersectionPoint.addItemListener(new ItemListener() 
		{
			public void itemStateChanged(ItemEvent arg0) 
			{
				panel_map.repaint();
			}
		});
		checkBoxShowIntersectionPoint.setSelected(true);
		checkBoxShowIntersectionPoint.setBounds(12, 200, 205, 23);
		checkBoxShowIntersectionPoint.setFocusPainted(false);
		panel_button.add(checkBoxShowIntersectionPoint);
		
		checkBoxShowRoad = new JCheckBox("Show Road");
		checkBoxShowRoad.addItemListener(new ItemListener() 
		{
			public void itemStateChanged(ItemEvent e) 
			{
				panel_map.repaint();
			}
		});
		checkBoxShowRoad.setSelected(true);
		checkBoxShowRoad.setBounds(12, 225, 115, 23);
		checkBoxShowRoad.setFocusPainted(false);
		panel_button.add(checkBoxShowRoad);
		
		label_ShortestPathLength = new JLabel("Shortest Path Length");
		label_ShortestPathLength.setBounds(12, 280, 205, 15);
		panel_button.add(label_ShortestPathLength);
		
		label_ShortestPathLengthValue = new JLabel("0");
		label_ShortestPathLengthValue.setBounds(12, 305, 205, 15);
		panel_button.add(label_ShortestPathLengthValue);
		
		label_MSTCost = new JLabel("MST Cost");
		label_MSTCost.setBounds(12, 350, 205, 15);
		panel_button.add(label_MSTCost);
		
		label_MSTCostValue = new JLabel("0");
		label_MSTCostValue.setBounds(12, 375, 205, 15);
		panel_button.add(label_MSTCostValue);
		
		label_MapSize = new JLabel("MapSize: " + MAX_X + " x " + MAX_Y);
		label_MapSize.setBounds(12, 475, 205, 15);
		panel_button.add(label_MapSize);
		
		lblRoadNumber = new JLabel("Road number (N)");
		lblRoadNumber.setBounds(12, 450, 115, 15);
		panel_button.add(lblRoadNumber);
		
		JSpinner spinner_RoadNumber = new JSpinner();
		spinner_RoadNumber.addChangeListener(new ChangeListener() 
		{
			public void stateChanged(ChangeEvent arg0) 
			{
				mapFrame.RandomRoadNumber = (int) spinner_RoadNumber.getValue();
			}
		});
		spinner_RoadNumber.setModel(new SpinnerNumberModel(50, 0, 100, 1));
		spinner_RoadNumber.setBounds(122, 447, 95, 22);
		panel_button.add(spinner_RoadNumber);
	}

	private void Initialize()
	{
		mapFrame = new MapFrame();
	}
}
