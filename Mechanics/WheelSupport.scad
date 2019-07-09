$fn=72;
axleSpacer2();
//pulleyBorder();

module axleSpacer(height=36, holeWidth=(5/16*25.4+1), width=(5/16*25.4+1)+10)
{
    difference()
    {
        cylinder(d=width, h=height, center=true);
        cylinder(d=holeWidth, h=height, center=true);
    }
}

module axleSpacer2(height=58, holeWidth=(5/8*25.4+1), width=(5/8*25.4+1)+10)
{
    difference()
    {
        cylinder(d=width, h=height, center=true);
        cylinder(d=holeWidth, h=height, center=true);
    }
}

module pulleyBorder(startDiam=152, endDiam=162, height=5)
{
    difference()
    {
        union()
        {
            difference()
            {
                cylinder(d1=endDiam, d2=startDiam, h=height, center=true);
                
                cylinder(d=135, h=height, center=true);
            }
            
            cube([135, 10, height], center=true);
            cube([10, 135, height], center=true);
            
            for (zAngle = [0:90:360])
            {
                rotate([0, 0, zAngle])
                translate([(2.75*25.4)/2, 0, 0])
                cylinder(d=18, h=height, center=true);
            }
            
            cylinder(d=35, h=height, center=true);
        }
        
        union()
        {
            for (zAngle = [0:90:360])
            {
                rotate([0, 0, zAngle])
                translate([(2.75*25.4)/2, 0, 0])
                cylinder(d=(5/16*25.4+1), h=40, center=true);
            }
            
            cylinder(d=25, h=height, center=true);
            
            rotate([0, 0, 45])
            translate([250, 0, 0])
            cube([500, 500, 100], center=true);
        }
    }
}