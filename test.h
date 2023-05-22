#pragma once
public class GraphicsList {
	private ArrayList graphicsList;
	private bool _isDirty;
	public  int  SelectionCount;
	private const string entryCount = "ObjectCount";
	private const string entryType = "ObjectType";
	public GraphicsList() {
		graphicsList = new ArrayList();
	}
	public int Count{
		get { return graphicsList.Count; }
	}
	public int SelectionCount{
		get {
			int n = 0;
			for each(DrawObject o in graphicsList) {
				if (o.Selected)
					n++;
			}
			return n;
		}
	}
	public DrawObject GetSelectedObject(int index) {
		int n = -1;
		for each(DrawObject o in graphicsList) {
			if (o.Selected) {
				n++;
				if (n == index)
					return o;
			}
		}
		return null;
	}
	public void Add(DrawObject obj) {
		graphicsList.Sort();
		for each(DrawObject o in graphicsList)
			o.ZOrder++;
			graphicsList.Insert(0, obj);
		}
	public void Append(DrawObject obj) {
		graphicsList.Add(obj);
	}



	public void UnselectAll() {
		for each(DrawObject o in graphicsList) {
			o.Selected = false;
		}
	}
	public void SelectAll() {
		for each(DrawObject o in graphicsList) {
			o.Selected = true;
		}
	}

	public bool DeleteSelection() {
		bool result = false;
		int n = graphicsList.Count;
		for (int i = n - 1; i >= 0; i--) {
			if (((DrawObject)graphicsList[i]).Selected) {
				graphicsList.RemoveAt(i);
				result = true;
			}
		}
		if (result)
			_isDirty = true;
		return result;
	}

	public void Draw(Graphics g) {
		int numberObjects = graphicsList.Count;
		for (int i = numberObjects - 1; i >= 0; i--){
			DrawObject o;
			o = (DrawObject)graphicsList[i];
			// Only draw objects that are visible
			if (o.IntersectsWith(Rectangle.Round(g.ClipBounds)))
				o.Draw(g);
				if (o.Selected)  	o.DrawTracker(g);
		}
	}


	public void LoadFromStream(SerializationInfo info, intorderNumber) {
		graphicsList = new ArrayList();
		// Get number of DrawObjects in this GraphicsList
		int  numberObjects = info.GetInt32(String.Format(CultureInfo.InvariantCulture,"{0}{1}", entryCount, orderNumber));
		for (inti = 0; i < numberObjects; i++) {
			stringtypeName;
			typeName = info.GetString(String.Format(CultureInfo.InvariantCulture,"{0}{1}", entryType, i));
			objectdrawObject;
			drawObject = Assembly.GetExecutingAssembly().CreateInstance(typeName);
			// Let the Draw Object load itself
			((DrawObject)drawObject).LoadFromStream(info, orderNumber, i);
			graphicsList.Add(drawObject);
		}
	}

	public void SaveToStream(SerializationInfo info, intorderNumber) {
	// First store the number of DrawObjects in the list
		info.AddValue(String.Format(CultureInfo.InvariantCulture,"{0}{1}", entryCount, orderNumber), graphicsList.Count);
	// Next save each individual object
		int i = 0;
		for each(DrawObject o in graphicsList) {
			info.AddValue(String.Format(CultureInfo.InvariantCulture,"{0}{1}",entryType, i),o.GetType().FullName);
			// Let each object save itself
			o.SaveToStream(info, orderNumber, i);
			i++;
		}
	}
	public bool Clear() {
		bool result = (graphicsList.Count > 0);
		graphicsList.Clear();
		if (result) 	_isDirty = false;
		return result;
	}