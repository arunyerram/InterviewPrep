import React from 'react'
import AnnouncementBanner from './Bottom'
import SignupSection from './SignupSection'
import PressReleases from './PresRelease'
import MissionSection from './Mission'
import Carousel2 from './Slider2'

import RecPage1 from './Recent copy/page'

const Invest = () => {
  return (
    <div>
        <Carousel2/>
        <MissionSection/>
       
        <PressReleases/>
        <RecPage1/>
        <SignupSection/>
        <AnnouncementBanner/>
    </div>
  )
}

export default Invest