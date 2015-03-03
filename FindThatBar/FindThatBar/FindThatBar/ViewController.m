//
//  ViewController.m
//  FindThatBar
//
//  Created by Karan Daryanani on 2/1/15.
//  Copyright (c) 2015 Karan Daryanani. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIImageView *Image;

- (IBAction)getBars:(id)sender;

@end

@implementation ViewController

@synthesize mapView;

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    mapView.delegate = self;
    self.locationManager = [[CLLocationManager alloc] init];
    self.locationManager.delegate = self;
    
    [self.locationManager requestWhenInUseAuthorization]; //Get the Users permission to use their location

    [self.locationManager startUpdatingLocation];
    
    mapView.showsUserLocation = YES;
    [mapView setMapType:MKMapTypeStandard];
    [mapView setZoomEnabled:YES];
    [mapView setScrollEnabled:YES];
    
   
    
    _Image.image =[UIImage imageNamed: @"bar-galaxy-free-cocktails-the_461835.jpg"];
    
    
}



- (NSString *)deviceLat {
    return [NSString stringWithFormat:@"%f", self.locationManager.location.coordinate.latitude];
}
- (NSString *)deviceLon {
    return [NSString stringWithFormat:@"%f", self.locationManager.location.coordinate.longitude];
}

-(void) getJSON
{
    NSString *latitude = [self deviceLat];
    NSString *longitude = [self deviceLon];
    
    NSLog(@"%@, %@", latitude, longitude);
    
    NSString *url = [NSString stringWithFormat:@"https://maps.googleapis.com/maps/api/place/search/json?location=%@,%@&radius=%@&types=%s&sensor=true&key=%@", latitude, longitude, [NSString stringWithFormat:@"16093"], "bar", kGOOGLE_API_KEY];
    
    //Formulate the string as URL object.
    NSURL *googleRequestURL=[NSURL URLWithString:url];
    
    // Retrieve the results of the URL.
    dispatch_async(kBgQueue, ^{
        NSData* data = [NSData dataWithContentsOfURL: googleRequestURL];
        [self performSelectorOnMainThread:@selector(fetchedData:) withObject:data waitUntilDone:YES];
    });
}

- (void)fetchedData:(NSData *)responseData {
    //Parse JSON data using Name Reference
    NSError* error;
    NSDictionary* json = [NSJSONSerialization
                          JSONObjectWithData:responseData
                          
                          options:kNilOptions
                          error:&error];
    
    //The results from Google will be an array obtained from the NSDictionary object with the key "results".
   // places = [json objectForKey:@"results"];
    
    //self.googlePlacesArrayFromAFNetworking = [responseObject objectForKey:@"name"];
    //Write out the data to the console.
    //NSLog(@"Google Places JSON Result: %@", places);
    
    //16093 = 10 miles in meters
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)getBars:(id)sender {
}
@end
