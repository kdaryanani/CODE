//
//  ViewController.h
//  FindThatBar
//
//  Created by Karan Daryanani on 2/1/15.
//  Copyright (c) 2015 Karan Daryanani. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <MapKit/MKAnnotation.h>
#import <CoreLocation/CoreLocation.h>

#define kGOOGLE_API_KEY @"AIzaSyAFVYYaPJPNaJFId4kML7d-Wr8ESbcY_hE"

#define kBgQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)

@interface ViewController : UIViewController <MKMapViewDelegate,  CLLocationManagerDelegate> { }

    @property(nonatomic, retain) IBOutlet MKMapView *mapView;
    @property(nonatomic, retain) CLLocationManager *locationManager;

@end

    