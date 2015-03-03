//
//  TableViewController.m
//  FindThatBar
//
//  Created by Karan Daryanani on 2/2/15.
//  Copyright (c) 2015 Karan Daryanani. All rights reserved.
//

#import "TableViewController.h"

@interface TableViewController ()

@end

@implementation TableViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //[UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
    //self.locationManager = [[CLLocationManager alloc] init];
    //self.locationManager.delegate = self;
    
   // [self.locationManager requestWhenInUseAuthorization]; //Get the Users permission to use their location
    
    
    
    //[self getJSON];
    
    
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
    places = [json objectForKey:@"results"];
    
    //self.googlePlacesArrayFromAFNetworking = [responseObject objectForKey:@"name"];
    //Write out the data to the console.
    NSLog(@"%@", places);
    
    //16093 = 10 miles in meters
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    // Return the number of rows in the section.
    return [places count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell"];
    
    if (cell ==nil){
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"Cell"];
    }

    cell.textLabel.text = [[places objectAtIndex:indexPath.row] objectForKey:@"name"];
    
    return cell;
}

- (IBAction)findBars:(id)sender {
    [self getJSON];
    [mainTableView reloadData];
}


@end
