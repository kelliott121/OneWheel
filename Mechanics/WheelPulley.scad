$fn=72;

//wheelPulleySpacer();

//translate([0, 0, 10])
wheelPulley();
//wheelPulleyCap();

module wheelSpacer()
{
    difference()
    {
        cylinder(d=(5/8)*25.4+5, h=42);
        cylinder(d=(5/8)*25.4+.6, h=42);
    }
}

module wheelPulley()
{
    difference()
    {
        union()
        {
            difference()
            {
                render()
                translate([0, 0, 0])
                import("stl/wheel_pulley_base.stl");
                
                cylinder(d=135, h=16);
            }
            
            translate([0, 0, 8])
            cube([135, 10, 16], center=true);
            translate([0, 0, 8])
            cube([10, 135, 16], center=true);
            
            for (zAngle = [0:90:360])
            {
                rotate([0, 0, zAngle])
                translate([(2.75*25.4)/2, 0, 0])
                cylinder(d=18, h=16);
            }
            
            cylinder(d=35, h=16);
        }
        
        union()
        {
            for (zAngle = [0:90:360])
            {
                rotate([0, 0, zAngle])
                translate([(2.75*25.4)/2, 0, 0])
                cylinder(d=(5/16*25.4+1), h=40);
            }
            
            cylinder(d=25, h=16);
        }
    }
}

module wheelPulleyCap()
{
    difference()
    {
        render()
        translate([0, 0, 2])
        import("stl/wheel_pulley_cap.stl");
        
        union()
        {
            for (zAngle = [0:90:360])
            {
                rotate([0, 0, zAngle])
                translate([(2.75*25.4)/2, 0, 0])
                cylinder(d=(5/16*25.4+1), h=40);
                
                cylinder(d=40, h=40, center=true);
            }
        }
    }
}

module wheelPulleySpacer()
{
    difference()
    {
        cylinder(d=155, h=4);
        
        union()
        {
            for (zAngle = [0:90:360])
            {
                rotate([0, 0, zAngle])
                translate([(2.75*25.4)/2, 0, 0])
                cylinder(d=(5/16*25.4+1), h=40);
                
                cylinder(d=40, h=40, center=true);
            }
        }
    }
}

module nut(width, height)
{
    ra = width*2/sqrt(3);
    cylinder(d = ra, h=height, $fn=6, center=true);
}