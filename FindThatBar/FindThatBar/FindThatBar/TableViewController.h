//
//  TableViewController.h
//  FindThatBar
//
//  Created by Karan Daryanani on 2/2/15.
//  Copyright (c) 2015 Karan Daryanani. All rights reserved.
//

#import <MapKit/MapKit.h>
#import <MapKit/MKAnnotation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>


#define kGOOGLE_API_KEY @"AIzaSyAFVYYaPJPNaJFId4kML7d-Wr8ESbcY_hE"

#define kBgQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

@interface TableViewController : UITableViewController <UITableViewDelegate, UITableViewDataSource,  CLLocationManagerDelegate> {

    NSArray *places;
    NSMutableData *data;
    
    IBOutlet UITableView *mainTableView;
    
}

@property(nonatomic, retain) CLLocationManager *locationManager;


@end
