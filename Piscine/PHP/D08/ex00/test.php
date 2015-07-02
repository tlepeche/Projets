<?PHP
require("Ship.class.php");
require("Fregate.class.php");

$new = new Fregate('1', 'fregate_test');
echo("name: ".$new->getName()." \n");
echo("width: ".$new->getWid()." \n");
echo("lenght: ".$new->getLenght()." \n");
echo("pc: ".$new->getPc()." \n");
echo("pp: ".$new->getPp()." \n");
echo("speed: ".$new->getSpeed()." \n");
echo("shield:  ".$new->getShield()." \n");
echo("man:  ".$new->getManeuvre()." \n");
echo"X : ".$new->getPosx()."\n";
echo"Y : ".$new->getPosy()."\n";
echo"ori : ".$new->getOri()."\n";


echo"fire(5, 30) -> ".$new->fire('5', '30')."\n";
echo"shield_dmg(5) -> ".$new->shield_dmg('5')."\n";
$new->setPosx(3);
$new->setPosy(5);
$new->setOri(-1);
echo"X : ".$new->getPosx()."\n";
echo"Y : ".$new->getPosy()."\n";
echo"ori : ".$new->getOri()."\n";
$new->setOri(1);
$new->setOri(1);
echo"ori : ".$new->getOri()."\n";
$new->setShield(2);
echo("shield:  ".$new->getShield()." \n");
echo"shield_dmg(1) -> ".$new->shield_dmg('1')."\n";
$new->setShield(2);
$new->pc_dmg(5);
echo"pc: ".$new->getPc()."\n";

?>
