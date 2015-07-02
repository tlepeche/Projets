<?PHP
abstract class Ship {
	protected $_id = 0;
	protected $_name = '';
	protected $_width = 0;
	protected $_lenght = 0;
	protected $_pc = 0;
	protected $_shield = 0;
	protected $_pp = 0;
	protected $_speed = 0;
	protected $_maneuvre = 0;
	protected $_posx = 0;
	protected $_posy = 0;
	protected $_ori = '1';
	/*orientation => 0 = forward ; 1 = right ; 2 = backward ; 3 = left */
	protected $_status = 'unplayed';

	public function __construct($id, $name, $width, $lenght, $pc, $pp, $speed, $shield, $maneuvre /*, $weapon*/, $x, $y, $ori)
	{
		$this->_id = $id;
		$this->_name = $name;
		$this->_width = $width;
		$this->_lenght = $lenght;
		$this->_pc = $pc;
		$this->_pp = $pp;
		$this->_speed = $speed;
		$this->_shield = $shield;
		$this->_maneuvre = $maneuvre;
		/*		$this->_weapon = $weapon;*/
		$this->_posx = $x;
		$this->_posy = $y;
		$this->_ori = $ori;
	}

	public function __destruct() {}

		public function move($move)
		{
			if ($move <= $this->getSpeed() )
				return true;
			else
				return false;
		}

	public function tab()
	{
		$i = $this->getX() - ($this->getWidth / 2);
		$j = $this->getY() - ($this->getLenght / 2);
		if ($this->getOri() == 2 || $this->getOri == 4)
			while ($i < ($this->getX() - ($this->getWidth / 2)) )
			{
				$tab[$i] = $this->getY();
				$i++;
			}
		else
			while ($j < ($this->getX() - ($this->getLenght / 2)) )
			{
				$tab[$this->getX()] = $j();
				$j++;
			}
		return $tab;
	}

	public function fire($pp_f, $dist)
	{
		$charges = 0 /*weapon charges*/ + $pp_f;
		$success = 0;
		if ($dist <= 30) /*short range*/
			$min = 4;
		else if ($dist <= 60) /*middle range*/
			$min = 5;
		else if ($dist <= 90) /*long range*/
			$min = 6;
		else 
			return 0; /* = miss */
		while ($charges > 0)
		{
			if ( rand(1, 6) >= $min )
				$success++;
			$charges--;
		}
		return $success;
	}

	/*renvoi les degat infliger sur la coque */
	protected function reduce_dmg($damage) 
	{
		return ($damage - $this->getShield());
	}

	public function shield_dmg($damage)
	{
		$this->_shield -= $damage;
		if ($this->_shield < 0)
			$this->_shield = 0;
		return ($this->_shield);
	}

	public function repair($pp_r)
	{
		$heal = 0;
		while ($pp_r > 0)
		{
			if (rand(1, 6) == 6)
				$heal++;
			$pp_r--;
		}
		return $heal;
	}

	/*GETTERS*/
	public function getName() {return $this->_name;}
		public function getWid() {return $this->_width;}
		public function getLenght() {return $this->_lenght;}
		public function getPc() {return $this->_pc;}
		public function getPp() {return $this->_pp;}
		public function getSpeed() {return $this->_speed;}
		public function getShield() {return $this->_shield;}
		public function getManeuvre() {return $this->_maneuvre;}
		public function getPosx() {return $this->_posx;}
		public function getPosy() {return $this->_posy;}
		public function getOri() {return $this->_ori;}
		public function getStatus() {return $this->_status;}
		/*SETTERS */

		public function setStatus($str)
		{
			$this->_status = $str;
		}

	public function setPosx($x)
	{
		$this->_posx = $this->_posx + $x;
	}

	public function setPosy($y)
	{
		$this->_posy = $this->_posy + $y;
	}

	/*var = 1 -> droite ; -1 -> gauche */
	public function setOri($var)
	{
		$this->_ori = ($this->_ori + $var) % 4;
		if ($this->_ori == -1)
			$this->_ori = 3;
	}

	public function setShield($pp_s)
	{
		$this->_shield += $pp_s;	
	}

	public function setPc($dmg)
	{
		$pc_lost = $this->reduce_dmg($dmg);
		$this->_pc -= $pc_lost;
		if ($this->_pc < 0)
			$this->_pc = 0;
	}

	public function setPp($pp)
	{
		$this->_pp = $pp;
	}

	public function setSpeed($speed)
	{
		$this->_speed = $pp;
	}
}
?>
