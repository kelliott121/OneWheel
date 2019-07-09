$fn = 72;

WheelWidth = 70;
WheelDiameter = 290;

//color("gray")
//tire();

/*
translate([0, 0, WheelWidth/4])
for (angle = [0:3])
{
    rotate([0, 0, 90*angle])
    translate([0, 1, 10])
    hubSegment();
}

translate([0, 0, -WheelWidth/4])
for (angle = [.5:3.5])
{
    rotate([0, 0, 90*angle])
    translate([0, 1, -10])
    hubSegment();
}
*/

hubSegment();

/*
translate([0, 0, WheelWidth/2+15])
render()
difference()
{
    import("stl/wheel_pulley.stl");
    
    union()
    {
        cylinder(d=56, h=100, center=true);
       
        for (spokeAngle = [0:45:360])
        {
            rotate([0, 0, spokeAngle])
            translate([0, 40, 0])
            cylinder(d=4, h=WheelWidth+1, center=true);
        }
    }
}
*/


module hubSegment(numSegments=4, diameter=265, thickness=6)
{
    angle = 360/numSegments;
    render()
    difference()
    {
        union()
        {
            difference()
            {
                cylinder(d=diameter, h=WheelWidth/2, center=true);
                cylinder(d=diameter-thickness, h=WheelWidth/2, center=true);
            }
            
            for (spokeAngle = [-45:45:45])
            {
                rotate([0, 0, spokeAngle])
                translate([0, -2.5, thickness/2 - WheelWidth/4])
                cube([thickness, diameter, thickness], center=true);
                
                rotate([0, 0, spokeAngle])
                translate([0, 40, thickness/2 - WheelWidth/4])
                cylinder(d=thickness+4.5, h=thickness, center=true);
                
                rotate([0, 0, spokeAngle])
                translate([0, 90, thickness/2 - WheelWidth/4])
                cylinder(d=thickness+4.5, h=thickness, center=true);
                
                translate([0, 0, thickness/2-WheelWidth/4])
                rotate([0, 0, spokeAngle])
                translate([0, 65, (4.5/2)])
                cube([thickness, 4.5+thickness, 4.5+thickness], center=true);
            }
            
            translate([0, 0, thickness/2-WheelWidth/4])
            cylinder(d=25+thickness*2, h=thickness, center=true);
        }
        
        union()
        {
            rotate([0, 0, angle/2])
            translate([-diameter/2, 0, 0])
            cube([diameter, diameter, WheelWidth+1], center=true);
            rotate([0, 0, -angle/2])
            translate([diameter/2, 0, 0])
            cube([diameter, diameter, WheelWidth+1], center=true);
            
            for (spokeAngle = [-45:45:45])
            {
                rotate([0, 0, spokeAngle])
                translate([0, 40, 0])
                cylinder(d=4.5, h=WheelWidth+1, center=true);
                
                rotate([0, 0, spokeAngle])
                translate([0, 90, 0])
                cylinder(d=4.5, h=WheelWidth+1, center=true);
                
                translate([0, 0, thickness/2-WheelWidth/4 + 4.5/2])
                rotate([0, 90, spokeAngle])
                translate([0, 65, 0])
                cylinder(d=4.5, h=WheelWidth+1, center=true);
            }
            cylinder(d=25, h=WheelWidth, center=true);
        }
    }
}

module tire(numSegments = 8)
{
    
    for (angle = [0:(numSegments-1)])
    {
        rotate([0, 0, angle*(360/numSegments)])
        translate([0, 2, 0])
        tireSegment(angle=(360/numSegments),thickness = 12.5, tireDiameter=WheelDiameter);
    }
    
    /*
    for (angle = [0:7])
    {
        rotate([0, 0, angle*45])
        translate([0, 2.5, 0])
        union()
        {
            rotate([0, 0, 21.25])
            tireSegment(angle=2.5,thickness = 6.25, tireDiameter=WheelDiameter - 12.5);
            rotate([0, 0, -21.25])
            tireSegment(angle=2.5,thickness = 6.25, tireDiameter=WheelDiameter - 12.5);
            rotate([0, 0, 0])
            tireSegment(angle=40,thickness = 12.5, tireDiameter=WheelDiameter);
        }
    }
    */
}

module tireSegment(angle=45, thickness=25, sweepAngle=22.5, tireDiameter)
{
    //for (scalar = [-1, 1])
    {
        //scale([1, 1, scalar])
        linear_extrude(height=WheelWidth, twist=sweepAngle, center=true)
        difference()
        {
            union()
            {
                circle(d=tireDiameter, center=true);
            }
            
            union()
            {
                circle(d=(tireDiameter - thickness*2), center=true);
                
                rotate([0, 0, angle/2])
                translate([-tireDiameter/2, 0, 0])
                square([tireDiameter, tireDiameter], center=true);
                rotate([0, 0, -angle/2])
                translate([tireDiameter/2, 0, 0])
                square([tireDiameter, tireDiameter], center=true);
            }
        }
    }
}