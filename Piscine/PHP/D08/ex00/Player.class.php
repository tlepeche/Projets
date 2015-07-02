<?PHP
Class Player {
	private $_name = 'player';
	private $_id = 0;
	private $_fleet = NULL;

	public function __construct( array $kwargs)
	{
		if (array_key_exists('name', $kwargs))
			$this->_name = $kwargs['name'];
		if (array_key_exists('id', $kwargs))
			$this->_id = $kwargs['id'];
		else
		{
			echo "an id is require to create a new player\n";
			exit ;
		}
	}

	public function add_fleet($ship)
	{
		$this->_fleet[] = $ship;
	}

	public function doc() { print(file_get_contents("./Player.doc.txt")); return ;}

	public function __toString()
	{
		echo$this->_name . " :\n";
		foreach ($this->_fleet as $key => $val)
			echo$key.': '.$val;
	}

	public function getName()
	{
		return ($this->_name);
	}

	public function getFleet()
	{
		return ($this->_fleet);
	}
}
?>
